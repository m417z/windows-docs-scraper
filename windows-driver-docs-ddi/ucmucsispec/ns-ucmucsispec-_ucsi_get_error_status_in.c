typedef struct _UCSI_GET_ERROR_STATUS_IN {
  union {
    UINT16 AsUInt16;
    struct {
      UINT16 UnrecognizedCommandError : 1;
      UINT16 NonExistentConnectorNumberError : 1;
      UINT16 InvalidCommandParametersError : 1;
      UINT16 IncompatibleConnectorPartnerError : 1;
      UINT16 CcCommunicationError : 1;
      UINT16 CommandFailureDueToDeadBattery : 1;
      UINT16 ContractNegotiationFailure : 1;
    };
  } ErrorInformation;
  UINT8 VendorDefined[14];
} UCSI_GET_ERROR_STATUS_IN, *PUCSI_GET_ERROR_STATUS_IN;