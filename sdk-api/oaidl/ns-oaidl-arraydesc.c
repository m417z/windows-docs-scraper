typedef struct tagARRAYDESC {
  TYPEDESC       tdescElem;
  USHORT         cDims;
  SAFEARRAYBOUND rgbounds[1];
} ARRAYDESC;