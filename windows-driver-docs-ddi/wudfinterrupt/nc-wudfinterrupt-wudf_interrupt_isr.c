typedef
BOOLEAN
_Function_class_(WUDF_INTERRUPT_ISR)
WUDF_INTERRUPT_ISR(
    _In_
    IWDFInterrupt* Interrupt,
    _In_
    ULONG MessageID,
    _In_
    ULONG Reserved
    );

typedef WUDF_INTERRUPT_ISR *PFN_WUDF_INTERRUPT_ISR;