typedef struct _D3DDDIARG_SETMATERIAL {
  [in] D3DCOLORVALUE Diffuse;
  [in] D3DCOLORVALUE Ambient;
  [in] D3DCOLORVALUE Specular;
  [in] D3DCOLORVALUE Emissive;
  [in] FLOAT         Power;
} D3DDDIARG_SETMATERIAL;