# IBDA_EasMessage::get_EasMessage

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_EasMessage** method retrieves an EAS message.

## Parameters

### `ulEventID` [in]

Specifies the event ID of the EAS message.

### `ppEASObject` [in, out]

Pointer to a pointer variable that receives a pointer to the **IUnknown** interface of the EAS object. The caller can query this object for its [ISCTE_EAS](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iscte_eas) interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method retrieves a counted reference to an **IUnknown** interface instance. The caller is responsible for releasing the interface when it is no longer required.

## See also

[IBDA_EasMessage Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_easmessage)