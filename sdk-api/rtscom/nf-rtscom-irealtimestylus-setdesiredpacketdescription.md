# IRealTimeStylus::SetDesiredPacketDescription

## Description

Requests properties to be included in the packet stream.

## Parameters

### `cProperties` [in]

Count of the properties specified by the *pPropertyGuids* parameter. Valid values are between 0 and 32, inclusive.

### `pPropertyGuids` [in]

The array of globally unique identifiers (GUIDs) for the properties requested to be included in the packet stream.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Events receive the actual packet properties in the following order.

| Packet order | Description |
| --- | --- |
| 1st position | Contains the x-coordinate data for the property regardless of whether X was specified in the [DesiredPacketDescription Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_desiredpacketdescription). |
| 2nd position | Contains the y-coordinate data for the property regardless of whether Y was specified in the [DesiredPacketDescription Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_desiredpacketdescription). |
| End position | Contains the packet status when packet status is in the [DesiredPacketDescription Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_desiredpacketdescription). |

**Note** The result of [IRealTimeStylus::GetPacketDescriptionData Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getpacketdescriptiondata) may not match the **IRealTimeStylus::SetDesiredPacketDescription Method** properties as some of the properties may not be supported by the tablet.

If the specified packet properties are not supported by the tablet devices, the property data is not returned and is not represented in the packet data array. If the same GUID appears multiple times in the *packetDescription* argument, only the first appearance is preserved and all following appearances are filtered out. The **IRealTimeStylus::SetDesiredPacketDescription Method** method can be called only while the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object is disabled.

Attempting to pass in 0 for *cProperties* and **NULL** for *pPropertyGuids* returns E_INVALIDARG.

Calls to the **IRealTimeStylus::SetDesiredPacketDescription Method** method are immediately reflected in the return value of the [IRealTimeStylus::GetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getdesiredpacketdescription) method.

#### Examples

The following C++ example code sets the properties that are requested to be included in the packet stream.

```cpp
GUID guidDesiredPacketDescription[] = { GUID_PACKETPROPERTY_GUID_X,
                                        GUID_PACKETPROPERTY_GUID_Y,
                                        GUID_PACKETPROPERTY_GUID_NORMAL_PRESSURE,
                                        GUID_PACKETPROPERTY_GUID_TANGENT_PRESSURE };

// Number of properties in the array
ULONG ulProperties = sizeof(guidDesiredPacketDescription) / sizeof(GUID);

// Set the packet information we'd like to get
if (SUCCEEDED(g_pRealTimeStylus->SetDesiredPacketDescription(ulProperties, guidDesiredPacketDescription)))
{
    TRACE("Set the desired packet description successfully.\n");
}

GUID* pGuids = NULL;

// See if setting the properties was successful
if (SUCCEEDED(g_pRealTimeStylus->GetDesiredPacketDescription(&ulProperties, &pGuids)))
{
    TRACE("The RealTimeStylus supports %d properties.\n", ulProperties);

    // Display the values of the GUIDs in debug output
    for (int i = 0; i < ulProperties; i++)
    {
        TRACE("GUID #%d == %d\n", i, pGuids[i]);
    }
}

```

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[IRealTimeStylus::GetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getdesiredpacketdescription)

[IRealTimeStylus::GetPacketDescriptionData Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getpacketdescriptiondata)

**RealTimeStylus Class**