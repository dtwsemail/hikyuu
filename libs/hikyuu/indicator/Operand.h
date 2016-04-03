/*
 * Operand.h
 *
 *  Created on: 2015年3月30日
 *      Author: Administrator
 */

#ifndef INDICATOR_OPERAND_H_
#define INDICATOR_OPERAND_H_

#include "OperandNode.h"

namespace hku {

class HKU_API Operand {
    HKU_API friend std::ostream & operator<<(std::ostream &, const Operand&);

public:
    Operand();
    Operand(const Indicator&);
    Operand(const Operand&);
    Operand(const Operand&, const Operand&);
    virtual ~Operand();

    Indicator calculate(const Indicator&);
    Indicator operator()(const Indicator& ind) {
        return calculate(ind);
    }

    Operand operator()(const Operand&);
    Operand operator+(const Operand&);
    Operand operator-(const Operand&);
    Operand operator*(const Operand&);
    Operand operator/(const Operand&);

    string name() const;
    void name(const string& name);

private:
    OperandNodePtr m_root;

#if HKU_SUPPORT_SERIALIZATION
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & BOOST_SERIALIZATION_NVP(m_root);
    }
#endif /* HKU_SUPPORT_SERIALIZATION */
};

typedef Operand OP;

} /* namespace hku */

#endif /* INDICATOR_OPERAND_H_ */