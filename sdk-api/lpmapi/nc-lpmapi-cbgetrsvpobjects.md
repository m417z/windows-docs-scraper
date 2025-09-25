## Description

The *cbGetRsvpObjects* function is a callback function for LPMs to asynchronously return results for
[LPM_GetRsvpObjects](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_getrsvpobjects) requests. LPMs call the
*cbGetRsvpObjects* function to asynchronously return policy data objects to the PCM for an
*LPM_GetRsvpObjects* request. An LPM should only use the
*cbGetRsvpObjects* function if it returned LPM_RESULTS_DEFER to the PCM's
*LPM_GetRsvpObjects* request.

## Parameters

### `LpmHandle` [in]

Unique handle for the LPM, as supplied in
[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize). The PCM will ignore any result that is not accompanied by a valid handle.

### `RequestHandle` [in]

Unique handle that distinguishes this request from all other requests, provided from the corresponding
[LPM_GetRsvpObjects](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_getrsvpobjects) request.

### `LpmError` [in]

Error value, used by the PCM to determine whether the policy data objects returned with this function should be used. Any value other than LPM_OK will result in the PCM ignoring the contents of **RsvpObjects*.

Note that if an LPM is returning an error, it should free buffers allocated during the
[LPM_GetRsvpObjects](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_getrsvpobjects) request processing; these buffers should have been allocated using the **MemoryAllocator** function, supplied within the
[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize) function as its *FreeMemory* parameter.

If no policy data objects are being returned, *LpmError* must be set to LPM_OK, *RsvpObjectsCount* must be set to zero, and **RsvpObjects* must be set to null. The LPM can force the SBM to stop sending out the RSVP message by setting the value of *LpmError* to LPV_DROP_MSG.

### `RsvpObjectsCount` [in]

Number of policy data objects being returned. If no policy data objects are being returned, the *LpmError* parameter must be set to LPM_OK, the *RsvpObjectsCount* parameter must be set to zero, and the **RsvpObjects* parameter must be set to null.

### `ppRsvpObjects` [in]

Array of pointers to policy data object. The buffer containing the policy data objects should be allocated using the **MemoryAllocator** function supplied within the [LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize) function. The Subnet Bandwidth Manager (SBM) will free the policy data objects when they are no longer needed.

If no policy data objects are being returned, *LpmError* must be set to LPM_OK, *RsvpObjectsCount* must be set to zero, and **RsvpObjects* must be set to null.

## Return value

Return values are defined by the application providing the callback.

## Remarks

LPMs do not need to send policy data options if only default options are required. Since the content of policy data objects are opaque to the PCM, no host-to-network order conversion of policy element headers and contents will be done by the PCM; the PCM expects LPMs to generate policy elements in the network order such that the receiver of the policy elements can correctly parse them. However, the policy data object header must be in host order to allow the PCM to merge policy elements (if possible or applicable).

From LPMs that support all PE types, the PCM expects complete policy data objects and their required policy data options. Furthermore, the PCM expects the policy data object header to be in host order; it is the responsibility of the LPM to process the host-to-network order conversions of policy options and policy elements.

If any LPM returns LPV_DROP_MSG, the SBM will not send out an RSVP refresh message, but will free the policy data objects returned by other LPMs (those that did not return LPV_DROP_MSG, if any). By not sending out RSVP refresh messages, a flow's RSVP state both upstream and downstream will begin to age, and eventually get deleted.

**Note** The SBM will send out the RSVP refresh message even if some or all LPMs fail to return policy data objects in a timely fashion, even though such an outgoing RSVP message may not contain all policy data objects it should.

## See also

[LPM_GetRsvpObjects](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_getrsvpobjects)

[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize)