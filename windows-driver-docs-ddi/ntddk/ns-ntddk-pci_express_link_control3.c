typedef struct _PCI_EXPRESS_LINK_CONTROL3 {
  union {
    struct {
      ULONG PerformEq : 1;
      ULONG LinkEqIntEn : 1;
      ULONG Reserved : 30;
    };
    ULONG AsULONG;
  };
} PCI_EXPRESS_LINK_CONTROL3, *PPCI_EXPRESS_LINK_CONTROL3;