# IDD_CX_CLIENT_CONFIG structure

## Description

The IDD_CX_CLIENT_CONFIG structure contains IDDCX callback functions that the display driver can use.

## Members

### `Size`

 The total size of the structure.

### `EvtIddCxDeviceIoControl`

 A pointer to the **PFN_IDD_CX_DEVICE_IO_CONTROL** function. This function can be used for communication between a user session process and the driver; typically this communication channel is used by a companion application to control some aspect of the driver.

### `EvtIddCxParseMonitorDescription`

 A pointer to the **PFN_IDD_CX_PARSE_MONITOR_DESCRIPTION** function.

### `EvtIddCxAdapterInitFinished`

 A pointer to the **PFN_IDD_CX_ADAPTER_INIT_FINISHED** function.

### `EvtIddCxAdapterCommitModes`

 A pointer to the **PFN_IDD_CX_ADAPTER_COMMIT_MODES** function.

### `EvtIddCxMonitorGetDefaultDescriptionModes`

 A pointer to the **PFN_IDD_CX_MONITOR_GET_DEFAULT_DESCRIPTION_MODES** function.

### `EvtIddCxMonitorQueryTargetModes`

 A pointer to the **PFN_IDD_CX_MONITOR_QUERY_TARGET_MODES** function.

### `EvtIddCxMonitorAssignSwapChain`

 A pointer to the **PFN_IDD_CX_MONITOR_ASSIGN_SWAPCHAIN** function.

### `EvtIddCxMonitorUnassignSwapChain`

 A pointer to the **PFN_IDD_CX_MONITOR_UNASSIGN_SWAPCHAIN** function.

### `EvtIddCxMonitorI2CTransmit`

 A pointer to the **PFN_IDD_CX_MONITOR_I2C_TRANSMIT** function.

### `EvtIddCxMonitorI2CReceive`

 A pointer to the **PFN_IDD_CX_MONITOR_I2C_RECEIVE** function.

### `EvtIddCxMonitorSetGammaRamp`

 A pointer to the **PFN_IDD_CX_MONITOR_SET_GAMMA_RAMP** function.

### `EvtIddCxMonitorOPMGetCertificateSize`

 A pointer to the **PFN_IDD_CX_MONITOR_OPM_GET_CERTIFICATE_SIZE** function.

### `EvtIddCxMonitorOPMGetCertificate`

 A pointer to the **PFN_IDD_CX_MONITOR_OPM_GET_CERTIFICATE** function.

### `EvtIddCxMonitorOPMCreateProtectedOutput`

 A pointer to the **PFN_IDD_CX_MONITOR_OPM_CREATE_PROTECTED_OUTPUT** function.

### `EvtIddCxMonitorOPMGetRandomNumber`

 A pointer to the **PFN_IDD_CX_MONITOR_OPM_GET_RANDOM_NUMBER** function.

### `EvtIddCxMonitorOPMSetSigningKeyAndSequenceNumbers`

 A pointer to the **PFN_IDD_CX_MONITOR_OPM_SET_SIGNING_KEY_AND_SEQUENCE_NUMBERS** function.

### `EvtIddCxMonitorOPMGetInformation`

 A pointer to the **PFN_IDD_CX_MONITOR_OPM_GET_INFOMATION** function.

### `EvtIddCxMonitorOPMConfigureProtectedOutput`

 A pointer to the **PFN_IDD_CX_MONITOR_OPM_CONFIGURE_PROTECTED_OUTPUT** function.

### `EvtIddCxMonitorOPMDestroyProtectedOutput`

 A pointer to the **PFN_IDD_CX_MONITOR_OPM_DESTROY_PROTECTED_OUTPUT** function.

### `EvtIddCxMonitorGetPhysicalSize`