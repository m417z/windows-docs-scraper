typedef struct RILCALLDISCONNECTDETAILS {
  RILCALLDISCONNECTDETAILSDISCONNECTGROUP dwDisconnectGroup;
  union {
    RILGPPCAUSE                    unGPPCause;
    RILGPPREJECTCAUSE              unGPPRejectCause;
    RILGPP2CAUSE                   unGPP2Cause;
    RILIMSSIPCAUSE                 unIMSSIPCause;
    RILCALLDISCONNECTDETAILSASCODE dwASCode;
    DWORD                          dwOtherCode;
  } RILCAUSEUNION;
  RILCAUSEUNION                           causeUnion;
} RILCALLDISCONNECTDETAILS, *LPRILCALLDISCONNECTDETAILS;