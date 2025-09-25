# CBADMITRESULT callback function

## Description

The
*cbAdmitResult* function is used by LPMs to return results for the
[LPM_AdmitRsvpMsg](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_admitrsvpmsg) request. LPMs should only use this function if they have returned LPM_RESULT_DEFER to the
*LPM_AdmitRsvpMsg* function call. The PCM will only accept results from this function within the result time limit established by each LPM through the *ResultTimeLimit* parameter of the
[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize) function.

## Parameters

### `LpmHandle` [in]

Unique handle for the LPM, as supplied in
[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize). The PCM will ignore any result that is not accompanied by a valid LPM handle.

### `RequestHandle` [in]

Unique handle that distinguishes this request from all other requests. LPMs must pass this handle to the PCM when returning results asynchronously for an individual request by calling
*cbAdmitResult*. The *RequestHandle* parameter becomes invalid once results are returned, requiring each request to get its own unique *RequestHandle* from the PCM.

### `ulPcmActionFlags` [in]

Policy Control Module action flags.

### `LpmError` [in]

LPM error code. Must be one of the following:

| Value | Meaning |
| --- | --- |
| **INV_LPM_HANDLE** | The supplied LPM handle is invalid. |
| **LPM_TIME_OUT** | The LPM has returned results after the time limit. |
| **INV_REQ_HANDLE** | The supplied request handle is invalid. |
| **DUP_RESULTS** | The LPM has already returned results for this request. |
| **INV_RESULTS** | The results supplied are invalid. |

### `PolicyDecisionsCount` [in]

The number of policy decisions provided in **pPolicyDecisions**.

### `pPolicyDecisions` [in]

Policy decisions, in the form of one or more **POLICY_DECISION** structures.

## Return value

This callback function does not return a value.

## Remarks

When a request has been rejected, the PCM will call the LPM to instruct it to delete the request's state. The LPM can choose to delete the request's state at any time during the rejection process. If the LPM deletes a request's state shortly after its rejection of the request, the LPM must be prepared to handle subsequent calls (by the PCM, through the
[LPM_DeleteState](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_deletestate) function) to delete the (already deleted) state.

The LPM does not need to maintain state for requests to which it returns LPV_DONT_CARE. However, the LPM must be prepared to handle
[LPM_DeleteState](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_deletestate) requests for this (nonexisting) state.

## See also

[LPM_AdmitRsvpMsg](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_admitrsvpmsg)

[LPM_DeleteState](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_deletestate)

[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize)