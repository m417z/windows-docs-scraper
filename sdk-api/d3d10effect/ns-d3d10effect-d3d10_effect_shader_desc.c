typedef struct _D3D10_EFFECT_SHADER_DESC {
  const BYTE *pInputSignature;
  BOOL       IsInline;
  const BYTE *pBytecode;
  UINT       BytecodeLength;
  LPCSTR     SODecl;
  UINT       NumInputSignatureEntries;
  UINT       NumOutputSignatureEntries;
} D3D10_EFFECT_SHADER_DESC;