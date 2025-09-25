# CLASS_MEDIA_CHANGE_CONTEXT structure

## Description

Contains information associated with a media change event.

## Members

### `MediaChangeCount`

The number of times that media has been changed since system startup.

### `NewState`

The state information. This member can be one of the following values from the
**MEDIA_CHANGE_DETECTION_STATE** enumeration type.

#### MediaUnknown (0)

#### MediaPresent (1)

#### MediaNotPresent (2)

#### MediaUnavailable (3)

## See also

[DBT_CUSTOMEVENT](https://learn.microsoft.com/windows/desktop/DevIO/dbt-customevent)

[DBT_DEVICEREMOVECOMPLETE](https://learn.microsoft.com/windows/desktop/DevIO/dbt-deviceremovecomplete)