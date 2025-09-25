typedef struct TF_DA_COLOR {
  TF_DA_COLORTYPE type;
  union {
    int      nIndex;
    COLORREF cr;
  };
} TF_DA_COLOR;