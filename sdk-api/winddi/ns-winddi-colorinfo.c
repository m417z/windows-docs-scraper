typedef struct _COLORINFO {
  CIECHROMA Red;
  CIECHROMA Green;
  CIECHROMA Blue;
  CIECHROMA Cyan;
  CIECHROMA Magenta;
  CIECHROMA Yellow;
  CIECHROMA AlignmentWhite;
  LDECI4    RedGamma;
  LDECI4    GreenGamma;
  LDECI4    BlueGamma;
  LDECI4    MagentaInCyanDye;
  LDECI4    YellowInCyanDye;
  LDECI4    CyanInMagentaDye;
  LDECI4    YellowInMagentaDye;
  LDECI4    CyanInYellowDye;
  LDECI4    MagentaInYellowDye;
} COLORINFO, *PCOLORINFO;