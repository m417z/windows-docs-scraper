# Tbsi_Get_TCG_Log function

## Description

Retrieves the most recent Windows Boot Configuration Log (WBCL), also referred to as a TCG log.

## Parameters

### `hContext` [in]

The TBS handle of the context that is retrieving the log. You get this parameter from a previous call to the [Tbsi_Context_Create](https://learn.microsoft.com/windows/desktop/api/tbs/nf-tbs-tbsi_context_create) function.

### `pOutputBuf` [out]

A pointer to a buffer to receive and store the WBCL. This parameter may be NULL to estimate the required buffer when the location pointed to by *pcbOutput* is also 0 on input.

### `pOutputBufLen` [in, out]

A pointer to an unsigned long integer that, on input, specifies the size, in bytes, of the output buffer. If the function succeeds, this parameter, on output, receives the size, in bytes, of the data pointed to by *pOutputBuf*. If the function fails, this parameter does not receive a value.

Calling the **Tbsi_Get_TCG_Log** function with a zero length buffer will return the size of the buffer required. **Windows Vista with SP1 and Windows Server 2008:** This functionality is not available.

## Return value

| Return code/value | Description |
| --- | --- |
| **TBS_SUCCESS**<br><br>0 (0x0) | The function succeeded. |
| **TBS_E_INTERNAL_ERROR**<br><br>2150121473 (0x80284001) | An internal software error occurred. <br><br>**Note** If TBS_E_INTERNAL_ERROR is returned, the system event log may contain event ID 16385 from the TBS event source with error code 0x80070032. This may indicate that the hardware platform does not provide a TCG event log to the operating system. Sometimes this can be resolved by installing a BIOS upgrade from the platform manufacturer. |
| **TBS_E_INVALID_OUTPUT_POINTER**<br><br>2150121475 (0x80284003) | A specified output pointer is not valid. |
| **TBS_E_INVALID_CONTEXT**<br><br>2150121476 (0x80284004) | The specified context handle does not refer to a valid context. |
| **TBS_E_INSUFFICIENT_BUFFER**<br><br>2150121477 (0x80284005) | The output buffer is too small. |
| **TBS_E_BUFFER_TOO_LARGE**<br><br>2150121486 (0x8028400E) | The output buffer is too large. |
| **TBS_E_TPM_NOT_FOUND**<br><br>2150121487 (0x8028400F) | A compatible Trusted Platform Module (TPM) Security Device cannot be found on this computer. |
| **TBS_E_DEACTIVATED**<br><br>2150121494 (0x80284016) | The Trusted Platform Module (TPM) Security Device is deactivated.<br><br>**Windows Vista with SP1 and Windows Server 2008:** This return value is not available. |

## Remarks

The **Tbsi_Get_TCG_Log** function returns the TCG Event Log for the system, and the buffer size depends on the number of events.

**Windows 10:**

The function may return a log that uses a format that is compatible with different hashing algorithms, depending on hardware capabilities and firmware settings. This log formats each event except the first as a TCG_PCR_EVENT2 structure:

```
typedef struct {
  TCG_PCRINDEX PCRIndex;
  TCG_EVENTTYPE EventType;
  TPML_DIGEST_VALUES Digests;
  UINT32 EventSize;
  UINT8 Event[EventSize];
} TCG_PCR_EVENT2;

typedef struct {
  UINT32 Count;
  TPMT_HA Digests;
} TPML_DIGEST_VALUES;

typedef struct {
  UINT16 HashAlg;
  UINT8 Digest[size_varies_with_algorithm];
} TPMT_HA;

```

The log formats the first event as a **TCG_PCR_EVENT** structure, which is described later in this Remarks section. The following table describes the values of the members of this structure for this first event.

| TCG_PCR_EVENT member | Value or description |
| --- | --- |
| **PCRIndex** | 0 |
| **EventType** | EV_NO_ACTION |
| **Digest** | 20 bytes of zeros |
| **EventSize** | The size of the **Event** member |
| **Event** | Has a type of **TCG_EfiSpecIdEventStruct** |

The following shows the syntax of the **TCG_EfiSpecIdEventStruct** structure that the **Event** member of the **TCG_PCR_EVENT** structure uses for the first log event.

```
typedef struct {
  BYTE[16] Signature;
  UINT32 PlatformClass;
  UINT8 SpecVersionMinor;
  UINT8 SpecVersionMajor;
  UINT8 SpecErrata;
  UINT8 UintNSize;
  UINT32 NumberOfAlgorithms;
  TCG_EfiSpecIdEventAlgorithmSize DigestSizes[NumberOfAlgorithms];
  UINT8 VendorInfoSize;
  UINT8 VendorInfo[VendorInfoSize];
} TCG_EfiSpecIdEventStruct;

typedef struct {
  UINT16 HashAlg;
  UINT16 DigestSize;
} TCG_EfiSpecIdEventAlgorithmSize;

```

The **Signature** member of the **TCG_EfiSpecIdEventStruct** structure is set to a null-terminated ASCII string of "Spec ID Event03" when the log uses the format that is compatible with different hashing algorithms. The **DigestSizes** array in this first event contains the digest sizes for the different hashing algorithms that the log uses. When a parser inspects an event of type **TCG_PCR_EVENT2**, the parser can parse the **TPML_DIGEST_VALUES** member without information about all of the hashing algorithms present. The digest sizes in the first event allow the parser to skip the correct number of bytes for the digests that are present.

If the **Signature** member is not set to a null-terminated ASCII string of "Spec ID Event03", then the events in the log are of type **TCG_PCR_EVENT**, and the **TCG_EfiSpecIdEventStruct** structure does not contain the **NumberOfAlgorithms** and **DigestSizes** members.

The log format that is compatible with different hashing algorithms allows the platform and operating system to use SHA1, SHA256, or other hashing algorithms. If the platform supports the SHA256 hashing algorithm and the uses the log format that is compatible with different hashing algorithms, the platform uses the SHA256 algorithm instead of SHA1.

**Windows Vista with SP1 and Windows Server 2008:** The function returns the log directly from the ACPI table and returns the entire ACPI allocated buffer, including the unused buffer after any events.

The Windows-defined events in the TCG event log are a tuple of {Type, Length, Value}. You can parse the log using the following TCG_PCR_EVENT structure from the [TCG PC Client spec](https://trustedcomputinggroup.org). You can create a correlation between lists of log events using the information in the [TPM PCP Toolkit](https://www.microsoft.com/download/details.aspx?id=52487&from=http%3A%2F%2Fresearch.microsoft.com%2Fen-us%2Fdownloads%2F74c45746-24ad-4cb7-ba4b-0c6df2f92d5d%2F) and the [TPM Main Specification](https://trustedcomputinggroup.org).

```
typedef struct {
  TCG_PCRINDEX PCRIndex;
  TCG_EVENTTYPE EventType;
  TCG_DIGEST Digest;
  UINT32 EventSize;
  UINT8 Event[EventSize];
} TCG_PCR_EVENT;
```

The memory size required for the *pOutputBuf* parameter should either be the constant in **TBS_IN_OUT_BUF_SIZE_MAX**, defined in the Tbs.h header file, or it should be obtained by calling the **Tbsi_Get_TCG_Log** function with a zero length buffer to get the required buffer size.

**Windows Vista with SP1 and Windows Server 2008:** Calling the **Tbsi_Get_TCG_Log** function with a zero length buffer to get the required buffer size is not supported. We recommend that you use the constant **TBS_IN_OUT_BUF_SIZE_MAX**, defined in the Tbs.h header file, for the memory size for the *pOutputBuf* parameter.

#### Examples

```cpp
#include <windows.h>
#include <tbs.h>
#pragma comment(lib, "Tbs.lib")

void main()
{
    TBS_RESULT result;
    TBS_HCONTEXT hContext;
    TBS_CONTEXT_PARAMS contextParams;
    contextParams.version = TBS_CONTEXT_VERSION_ONE;
    result = Tbsi_Context_Create(&contextParams, &hContext);
    if (result == TBS_SUCCESS)
    {
        UINT32 iLogSize = TBS_IN_OUT_BUF_SIZE_MAX;
        BYTE* pLogBuffer = new BYTE[iLogSize];
        result = Tbsi_Get_TCG_Log(hContext, pLogBuffer, &iLogSize);
    }
}

```