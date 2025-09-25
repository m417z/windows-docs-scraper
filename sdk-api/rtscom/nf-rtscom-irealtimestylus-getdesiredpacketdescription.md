# IRealTimeStylus::GetDesiredPacketDescription

## Description

Retrieves the list of properties that have been requested to be included in the packet stream.

## Parameters

### `pcProperties` [in, out]

The size, in bytes, of the *ppPropertyGUIDS* buffer.

### `ppPropertyGuids` [out]

 A pointer to a list of GUIDs specifying which properties, such as X, Y, and NormalPressure, are present in the packet data. For a list of predefined properties, see [PacketPropertyGuids Constants](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants).

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

Use this method to get the array of packet properties to which the [IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus) object has subscribed by calling [IRealTimeStylus::SetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setdesiredpacketdescription). The packet properties are represented by an array of globally unique identifiers (GUIDs). For a complete list of properties for which you can retrieve metrics, see the [PacketPropertyGuids Constants](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants).

The default is an array of GUIDs that contains the X, Y and normal pressure GUIDs.

The **IRealTimeStylus::GetDesiredPacketDescription Method** uses [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) to allocate space for the GUIDs. The caller should call [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when the array is no longer needed.

If called on a child [IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus) object (cascading configuration) and connected, this method returns the parent's packet description if connected, otherwise this method returns the default (X, Y, pressure) or whatever properties were set in an earlier call to the [IRealTimeStylus::SetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setdesiredpacketdescription).

The following list describes how the [IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus) object orders the packet property GUIDs.

* By default, the **IRealTimeStylus::GetDesiredPacketDescription Method** method returns GUID_X, GUID_Y, and GUID_NORMAL_PRESSURE.
* The X and Y GUIDs are always returned in the first two positions in the array by the **IRealTimeStylus::GetDesiredPacketDescription Method** method, whether they were specified in a previous call to the [IRealTimeStylus::SetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setdesiredpacketdescription) method.
* If GUID_PACKET_STATUS is specified in the call to the [IRealTimeStylus::SetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setdesiredpacketdescription) method, GUID_PACKET_STATUS is always returned in the last position in the array by the **IRealTimeStylus::GetDesiredPacketDescription Method** method.
* If any GUIDs are specified more than once in the call to the [IRealTimeStylus::SetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setdesiredpacketdescription) method, each GUID occurs only once in the array returned by the **IRealTimeStylus::GetDesiredPacketDescription Method** method.

#### Examples

The following C++ example code gets the list of properties included in the packet stream.

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

[IRealTimeStylus::SetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setdesiredpacketdescription)

**RealTimeStylus Class**