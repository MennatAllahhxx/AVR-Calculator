#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Var,BitNo) ((Var)|=(1<<(BitNo)))
#define CLR_BIT(Var,BitNo) ((Var)&=~(1<<(BitNo)))
#define TGL_BIT(Var,BitNo) ((Var)^=(1<<(BitNo)))
#define GET_BIT(Var,BitNo) (((Var)>>BitNo)&0X01)

#endif