# GetPreferredPacketDescription function

## Description

Retrieves a packet description that contains the packet properties the recognizer uses.

## Parameters

### `hrec`

Handle to the recognizer.

### `pPacketDescription`

Describes the content of the packets the recognizer uses. For more information, see the [PACKET_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ns-tpcshrd-packet_description) structure.

To retrieve the packet description, initialize the packet description with zeroes and call the **GetPreferredPacketDescription** function. The function populates the property and button counts, which you use to allocate space for the pPacketProperties and pguidButtons members of the [PACKET_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ns-tpcshrd-packet_description) structure. Call the function again to populate the rest of the packet description.

The pguidButtons member of the [PACKET_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ns-tpcshrd-packet_description) structure may be zero when **GetPreferredPacketDescription** returns. This means the packets have no button data, so this member does not have any pguidButtons allocated. In this case, the calling function should leave the pointer **NULL**.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | The parameter is an invalid pointer. |
| **TPC_E_INSUFFICIENT_BUFFER** | The *pPacketDescription* buffer is too small. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |

## Remarks

Typically, recognizers use the (x, y) coordinate properties and ignore the others. If you save the ink to a file for recognition at a later time, use the preferred packet description to only save those properties that the recognizer uses.

## See also

[AddStroke Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-addstroke)

[PACKET_DESCRIPTION Structure](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ns-tpcshrd-packet_description)