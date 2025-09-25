typedef struct _D3DKMT_SUBMITCOMMANDFLAGS {
  [in] UINT NullRendering : 1;
  [in] UINT PresentRedirected : 1;
       UINT NoKmdAccess : 1;
       UINT Reserved : 29;
} D3DKMT_SUBMITCOMMANDFLAGS;