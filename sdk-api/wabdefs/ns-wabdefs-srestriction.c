typedef struct _SRestriction {
  ULONG rt;
  union {
    SComparePropsRestriction resCompareProps;
    SAndRestriction          resAnd;
    SOrRestriction           resOr;
    SNotRestriction          resNot;
    SContentRestriction      resContent;
    SPropertyRestriction     resProperty;
    SBitMaskRestriction      resBitMask;
    SSizeRestriction         resSize;
    SExistRestriction        resExist;
    SSubRestriction          resSub;
    SCommentRestriction      resComment;
  } res;
} *LPSRestriction, SRestriction;