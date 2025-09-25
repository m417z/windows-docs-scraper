typedef struct _MI_SessionCallbacks {
  void  *callbackContext;
  void(MI_Application *application, void *callbackContext,MI_Uint32 channel, const MI_Char *message) * )(writeMessage;
  void(MI_Application *application, void *callbackContext,MI_Instance *instance) * )(writeError;
} MI_SessionCallbacks;