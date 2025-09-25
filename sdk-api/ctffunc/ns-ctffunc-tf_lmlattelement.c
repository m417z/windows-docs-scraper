typedef struct TF_LMLATTELEMENT {
  DWORD dwFrameStart;
  DWORD dwFrameLen;
  DWORD dwFlags;
  union {
    INT iCost;
  };
  BSTR  bstrText;
} TF_LMLATTELEMENT;