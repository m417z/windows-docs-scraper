typedef struct _DXGKARG_DISPLAYDETECTCONTROL {
  [in] D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId : 24;
  [in] DXGK_DISPLAYDETECTCONTROLTYPE  Type : 4;
  [in] UINT                           NonDestructiveOnly : 1;
       UINT                           Reserved : 3;
} DXGKARG_DISPLAYDETECTCONTROL;