# LPM_Initialize function

## Description

The
*LPM_Initialize* function initializes a local policy module (LPM). This occurs when the Admission Control Service needs to do policy based–admission control, such as when an SBM becomes the Designated Subnet Bandwidth Manager (DSBM). LPMs should initialize themselves, synchronously, before returning.

## Parameters

### `LpmHandle` [in]

Unique handle for the LPM, assigned by the PCM.

### `pLpmInitInfo` [in]

Pointer to an LPM_INIT_INFO structure containing LPM initialization information.

### `pLpmVersionNumber` [out]

Version of LPM being requested.

### `pSupportedPeType` [out]

Valid policy element (PE) type that the LPM uses to make policy based–admission control decisions. Each LPM can only support one PE type, though future versions may allow an LPM to support multiple PE types. Reserved PE types are defined in Lpmapi.h. For more information about policy element types, see
[Policy Elements](https://learn.microsoft.com/previous-versions/windows/desktop/qos/policy-elements).

It is possible for a single DLL to support multiple PE types by having the DLL name entered multiple times in the PCM configuration data. Under such circumstances, the PCM will load and call the same LPM_Initialize routine multiple times; it is the LPM's responsibility to return different PE types for these additional calls.

LPMs can return a special PE type, LPM_ALL_PE_TYPES, to indicate that it will make policy based–admission control decisions based on all policy data objects. In this scenario, the PCM will assume that this LPM understands how to generate policy data objects for outgoing messages that the PCM is not able to understand.

### `Reserved` [out]

Reserved for future use.

## Return value

If the LPM is initialized successfully, and a valid PE type is returned in *pSupportedPeType*, the return value will be LPM_OK. The PCM treats any value other than LPM_OK as an error, and unloads the DLL (LPMs are always implemented as DLLs). If a value other than LPM_OK is returned or *pSupportedPeType* is invalid, the PCM writes a record to the Event Log and includes the name of the DLL and the returned error value.

## See also

[LPM_AdmitRsvpMsg](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_admitrsvpmsg)

[LPM_GetRsvpObjects](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_getrsvpobjects)

[PALLOCMEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-pallocmem)

[PFREEMEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-pfreemem)