#include "stdafx.h"

#include "Assert.h"
#include "X64CodeGenerator.h"


namespace NativeJIT
{


    X64CodeGenerator::X64CodeGenerator(std::ostream& out)
        : m_out(out)
    {
    }


    unsigned X64CodeGenerator::GetRXXCount() const
    {
        return c_rxxRegisterCount;
    }


    unsigned X64CodeGenerator::GetXMMCount() const
    {
        return c_xmmRegisterCount;
    }


    // dest <== dest op src
    void X64CodeGenerator::Op(char const* op, Register<8, false> dest, Register<8, false> src)
    {
        m_out << op << " " << dest.GetName() << ", " << src.GetName() << std::endl;
    }


    // dest <== dest op value
    void X64CodeGenerator::Op(char const* op, Register<8, false> dest, unsigned __int64 value)
    {
        m_out << op << " " << dest.GetName() << ", " << value << std::endl;
    }


    // dest <== dest op [base + offset]
    void X64CodeGenerator::Op(char const* op, Register<8, false> dest, Register<8, false> base, unsigned __int64 offset)
    {
        m_out << op << " " << dest.GetName() << ", [" << base.GetName() << " + " << offset << "]" << std::endl;
    }


    // dest <== op dest
    void X64CodeGenerator::Op(char const* op, Register<8, false> dest)
    {
        m_out << op << " " << dest.GetName() << std::endl;
    }


    // op
    void X64CodeGenerator::Op(char const* op)
    {
        m_out << op << std::endl;
    }
}