typedef struct _D3DDDI_LIGHT {
  [in] D3DLIGHTTYPE  Type;
  [in] D3DCOLORVALUE Diffuse;
  [in] D3DCOLORVALUE Specular;
  [in] D3DCOLORVALUE Ambient;
  [in] D3DVECTOR     Position;
  [in] D3DVECTOR     Direction;
  [in] FLOAT         Range;
  [in] FLOAT         Falloff;
  [in] FLOAT         Attenuation0;
  [in] FLOAT         Attenuation1;
  [in] FLOAT         Attenuation2;
  [in] FLOAT         Theta;
  [in] FLOAT         Phi;
} D3DDDI_LIGHT;