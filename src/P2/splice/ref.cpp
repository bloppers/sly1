#include <splice/ref.h>
#include <splice/vecmat.h>

CRef::CRef()
{
    m_tagk = TAGK_Nil;
}

INCLUDE_ASM(const s32, "P2/splice/ref", __4CRefRC4CRef);

INCLUDE_ASM(const s32, "P2/splice/ref", _$_4CRef);

INCLUDE_ASM(const s32, "P2/splice/ref", __as__4CRefRC4CRef);

INCLUDE_ASM(const s32, "P2/splice/ref", __eq__4CRefRC4CRef);

INCLUDE_ASM(const s32, "P2/splice/ref", CloneTo__4CRefP4CRefP6CFrame);

INCLUDE_ASM(const s32, "P2/splice/ref", Decref__4CRef);

INCLUDE_ASM(const s32, "P2/splice/ref", Incref__4CRef);
/* todo: match rodata
void CRef::Incref()
{
    switch(m_tagk)
    {
        case TAGK_Vector:
            IncrefVector(m_tag.m_pvector);
            break;
        case TAGK_Matrix:
            IncrefMatrix(m_tag.m_pmatrix);
            break;
        case TAGK_Clq:
            IncrefClq(m_tag.m_pclq);
            break;
        case TAGK_Lm:
            IncrefLm(m_tag.m_plm);
            break;
        case TAGK_Smp:
            IncrefSmp(m_tag.m_psmp);
            break;
    }
}*/

void CRef::SetTag(TAGK tagk)
{
    Decref();
    m_tagk = tagk;
}

void CRef::SetS32(s32 n)
{
    Decref();
    m_tag.m_n = n;
    m_tagk = TAGK_S32;
}

void CRef::SetF32(f32 g)
{
    Decref();
    m_tag.m_g = g;
    m_tagk = TAGK_F32;
}

void CRef::SetBool(int fBool)
{
    Decref();
    if (fBool)
    {
        m_tag.m_bool = 1;
    }
    else
    {
        m_tag.m_bool = 0;
    }
    m_tagk = TAGK_Bool;
}

void CRef::SetSymid(u32 symid)
{
    Decref();
    m_tag.m_symid = symid;
    m_tagk = TAGK_Symid;
}

void CRef::SetBifk(BIFK bifk)
{
    Decref();
    m_tag.m_bifk = bifk;
    m_tagk = TAGK_Bifk;
}

void CRef::SetPair(CPair* ppair)
{
    Decref();
    m_tag.m_ppair = ppair;
    m_tagk = TAGK_Pair;
}

void CRef::SetProc(CProc* pproc)
{
    Decref();
    m_tag.m_pproc = pproc;
    m_tagk = TAGK_Proc;
}

void CRef::SetVector(VECTOR* pvector)
{
    IncrefVector(pvector);
    Decref();
    m_tag.m_pvector = pvector;
    m_tagk = TAGK_Vector;
}

void CRef::SetMatrix(MATRIX4* pmatrix)
{
    IncrefMatrix(pmatrix);
    Decref();
    m_tag.m_pmatrix = pmatrix;
    m_tagk = TAGK_Matrix;
}

void CRef::SetClq(CLQ* pclq)
{
    IncrefClq(pclq);
    Decref();
    m_tag.m_pclq = pclq;
    m_tagk = TAGK_Clq;
}

void CRef::SetLm(LM* plm)
{
    IncrefLm(plm);
    Decref();
    m_tag.m_plm = plm;
    m_tagk = TAGK_Lm;
}

void CRef::SetSmp(SMP* psmp)
{
    IncrefSmp(psmp);
    Decref();
    m_tag.m_psmp = psmp;
    m_tagk = TAGK_Smp;
}

void CRef::SetBasic(BASIC* pbasic)
{
    Decref();
    m_tag.m_pbasic = pbasic;
    m_tagk = TAGK_Basic;
}

void CRef::SetMethod(CMethod* pmethod)
{
    Decref();
    m_tag.m_pmethod = pmethod;
    m_tagk = TAGK_Method;
}

INCLUDE_ASM(const s32, "P2/splice/ref", RefCoerceS32__4CRef);

INCLUDE_ASM(const s32, "P2/splice/ref", RefCoerceF32__4CRef);
