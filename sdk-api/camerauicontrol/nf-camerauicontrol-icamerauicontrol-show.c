HRESULT Show(
  [in] IUnknown                           *pWindow,
  [in] CameraUIControlMode                mode,
       CameraUIControlLinearSelectionMode selectionMode,
  [in] CameraUIControlCaptureMode         captureMode,
  [in] CameraUIControlPhotoFormat         photoFormat,
  [in] CameraUIControlVideoFormat         videoFormat,
  [in] BOOL                               bHasCloseButton,
  [in] ICameraUIControlEventCallback      *pEventCallback
);