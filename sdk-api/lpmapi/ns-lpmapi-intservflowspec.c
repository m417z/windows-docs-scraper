typedef struct {
  IntServMainHdr spec_mh;
  union {
    CtrlLoadFlowspec CL_spec;
    GuarFlowSpec     G_spec;
    QualAppFlowSpec  Q_spec;
  } spec_u;
} IntServFlowSpec;