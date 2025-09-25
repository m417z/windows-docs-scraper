# LPM_DeleteState function

## Description

The
*LPM_DeleteState* function is called by the PCM to delete the LPMs' RSVP state information. RSVP states are deleted on various occasions, including when the SBM receives RSVP TEAR/ERR messages, or when an RSVP state times out. The
*LPM_DeleteState* function call is synchronous. The PCM does not expect any results from the LPM for this request.

## Parameters

### `pRcvdIfAddr` [in]

Pointer to the interface on which the RSVP TEAR message was received. The received interface IP address is supplied as the RSVP HOP object, and the Logical Interface Handle is set to the SNMP Index. If the PCM is calling the
*LPM_DeleteState* function for any reason other than an RSVP TEAR message, this parameter can be null. Note that interface index numbers can change with the addition and deletion of interfaces, due to the Plug and Play features of Windows 2000.

### `RsvpMsgType` [in]

RSVP message type for which the LPM should delete its state.

### `pRsvpSession` [in]

Pointer to the RSVP session object for which the LPM should delete its state. This value is never null.

### `pRsvpFromHop` [in]

Pointer to an
RSVP HOP object identifying the node that sent the TEAR message. LPMs can use this parameter to locate state information.

### `pResvStyle` [in]

Pointer to an argument that specifies the RSVP reservation style for RSVP RESV_TEAR messages. LPMs can use this parameter to locate state information.

### `FilterSpecCount` [in]

Specifies the number of FilterSpecs in *FilterSpecList*. For RESV messages, *FilterSpecCount* is dependent on *RsvpStyle*. For PATH messages, this value will always be 1.

### `ppFilterSpecList` [in]

Array of FilterSpec pointers. Note that the contents of *FilterSpecList* is dependent on *RsvpStyle*; if *RsvpMsgType* is RSVP_PATH then *FilterSpecList* specifies the SenderTemplate, if *RsvpMsgType* is RSVP_RESV then *FilterSpecList* is the list of filters for which the RESV state needs to be deleted.

### `TearDownReason` [in]

Reason for deleting the state. Possible values are:

#### RCVD_PATH_TEAR

#### RCVD_RESV_TEAR

#### ADM_CTRL_FAILED

#### STATE_TIMEOUT

#### FLOW_DURATION

LPMs can use *DeleteReason* for statistical gathering or any other use.

## Remarks

The PCM will call the
*LPM_DeleteState* function for each LPM; LPMs should be prepared to handle
*LPM_DeleteState* for a nonexistent state, as described further in the Remarks section of the
[cbAdmitResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-cbadmitresult) function.

## See also

[cbAdmitResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-cbadmitresult)