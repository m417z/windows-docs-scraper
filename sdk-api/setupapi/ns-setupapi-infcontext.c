typedef struct _INFCONTEXT {
  PVOID Inf;
  PVOID CurrentInf;
  UINT  Section;
  UINT  Line;
} INFCONTEXT, *PINFCONTEXT;