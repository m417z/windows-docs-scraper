DWORD PXEAPI PxeRegisterCallback(
  [in] HANDLE            hProvider,
  [in] PXE_CALLBACK_TYPE CallbackType,
  [in] PVOID             pCallbackFunction,
  [in] PVOID             pContext
);