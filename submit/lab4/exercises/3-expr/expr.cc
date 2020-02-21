#include "expr.hh"

#include <string>
#include <sstream>

double
IntExpr::eval() const {
  return value;
}

std::string
IntExpr::toString() const
{
  std::stringstream s;
  s << value;
  return s.str();
}

static std::string
binaryExprToString(std::string op, ExprPtr left, ExprPtr right)
{
  std::stringstream s;
  s << "(" << *left << ") " << op << " (" << *right << ")";
  return s.str();
}

double
AddExpr::eval() const{
  return left.get()->eval() + right.get()->eval();
}

std::string
AddExpr::toString() const
{
  return binaryExprToString("+", left, right);
}

double
SubExpr::eval() const{
  return left.get()->eval() - right.get()->eval();
}

std::string
SubExpr::toString() const
{
  return binaryExprToString("-", left, right);
}

double
MulExpr::eval() const{
  return left.get()->eval() * right.get()->eval();
}

std::string
MulExpr::toString() const
{
  return binaryExprToString("*", left, right);
}

double
DivExpr::eval() const {
  return (int)left.get()->eval() / (int)right.get()->eval();
}

std::string
DivExpr::toString() const
{
  return binaryExprToString("/", left, right);
}

