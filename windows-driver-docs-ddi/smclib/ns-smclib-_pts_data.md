# _PTS_DATA structure

## Description

The PTS_DATA structure is used for protocol type selection (PTS).

## Members

### `Type`

Controls how the remaining members of this structure are calculated. This member can have one of the following values:

#### PTS_TYPE_DEFAULT

Calculates standard parameters for PTS.

#### PTS_TYPE_OPTIMAL

Calculates the best possible parameters for PTS.

#### PTS_TYPE_USER

Calculates user-defined parameters for PTS.

The smart card driver library populates the remaining members of this structure when the reader driver calls its [SmartcardUpdateCardCapabilities (WDM)](https://learn.microsoft.com/previous-versions/ff548972(v=vs.85)) routine. However, in some cases, the reader driver might be responsible for setting these parameters. For example, if a PTS request that specifies optimal parameters fails, the reader driver can set the parameters in a callback function that specifies the protocol. To specify the protocol, the callback function should set the type to PTS_TYPE_DEFAULT and call **SmartcardUpdateCardCapabilities** again.

### `Fl`

The Fl value to use as part of PTS1 for the PTS request.

### `Dl`

The Dl value to use as part of PTS1 for the PTS request.

### `CLKFrequency`

Contains the clock frequency. Some smart card readers must be programmed by using the new clock frequency to use after the PTS request.

### `DataRate`

Contains the new data rate. Some smart card readers (for example, serial readers) must be set to the new data rate to use after a PTS request.

### `StopBits`

Contains the number of stop bits to use with the inserted card.

## Remarks

The smart card reader driver library assigns values to the members of this structure before it calls the callback function that sets the protocol. The driver library considers the characteristics of the inserted smart card, the supported clock frequencies, and supported data rates of the reader when it assigns the values.