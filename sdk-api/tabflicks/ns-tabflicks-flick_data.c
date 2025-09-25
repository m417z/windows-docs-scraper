typedef struct FLICK_DATA {
  FLICKACTION_COMMANDCODE iFlickActionCommandCode : 5;
  FLICKDIRECTION          iFlickDirection : 3;
  BOOL                    fControlModifier : 1;
  BOOL                    fMenuModifier : 1;
  BOOL                    fAltGRModifier : 1;
  BOOL                    fWinModifier : 1;
  BOOL                    fShiftModifier : 1;
  INT                     iReserved : 2;
  BOOL                    fOnInkingSurface : 1;
  INT                     iActionArgument : 16;
} FLICK_DATA;