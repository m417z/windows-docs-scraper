typedef struct {
  smiUINT32 syntax;
  union {
    smiINT    sNumber;
    smiUINT32 uNumber;
    smiCNTR64 hNumber;
    smiOCTETS string;
    smiOID    oid;
    smiBYTE   empty;
  } value;
} smiVALUE, *smiLPVALUE;