typedef struct _STROBJ {
  ULONG    cGlyphs;
  FLONG    flAccel;
  ULONG    ulCharInc;
  RECTL    rclBkGround;
  GLYPHPOS *pgp;
  LPWSTR   pwszOrg;
} STROBJ;