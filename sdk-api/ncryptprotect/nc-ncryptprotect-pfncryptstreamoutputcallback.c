PFNCryptStreamOutputCallback Pfncryptstreamoutputcallback;

SECURITY_STATUS Pfncryptstreamoutputcallback(
  [in] void *pvCallbackCtxt,
  [in] const BYTE *pbData,
       SIZE_T cbData,
       BOOL fFinal
)
{...}