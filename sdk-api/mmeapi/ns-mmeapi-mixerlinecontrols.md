# MIXERLINECONTROLS structure

## Description

The **MIXERLINECONTROLS** structure contains information about the controls of an audio line.

## Members

### `cbStruct`

Size, in bytes, of the **MIXERLINECONTROLS** structure. This member must be initialized before calling the [mixerGetLineControls](https://learn.microsoft.com/previous-versions/dd757302(v=vs.85)) function. The size specified in this member must be large enough to contain the **MIXERLINECONTROLS** structure. When **mixerGetLineControls** returns, this member contains the actual size of the information returned. The returned information will not exceed the requested size, nor will it be smaller than the **MIXERLINECONTROLS** structure.

### `dwLineID`

Line identifier for which controls are being queried. This member is not used if the MIXER_GETLINECONTROLSF_ONEBYID flag is specified for the [mixerGetLineControls](https://learn.microsoft.com/previous-versions/dd757302(v=vs.85)) function, but the mixer device still returns this member in this case. The **dwControlID** and **dwControlType** members are not used when MIXER_GETLINECONTROLSF_ALL is specified.

### `dwControlID`

Control identifier of the desired control. This member is used with the MIXER_GETLINECONTROLSF_ONEBYID flag for the [mixerGetLineControls](https://learn.microsoft.com/previous-versions/dd757302(v=vs.85)) function to retrieve the control information of the specified control. Note that the **dwLineID** member of the **MIXERLINECONTROLS** structure will be returned by the mixer device and is not required as an input parameter. This member overlaps with the **dwControlType** member and cannot be used in conjunction with the MIXER_GETLINECONTROLSF_ONEBYTYPE query type.

### `dwControlType`

Class of the desired [Control Types](https://learn.microsoft.com/windows/desktop/Multimedia/control-types). This member is used with the MIXER_GETLINECONTROLSF_ONEBYTYPE flag for the [mixerGetLineControls](https://learn.microsoft.com/previous-versions/dd757302(v=vs.85)) function to retrieve the first control of the specified class on the line specified by the **dwLineID** member of the **MIXERLINECONTROLS** structure. This member overlaps with the **dwControlID** member and cannot be used in conjunction with the MIXER_GETLINECONTROLSF_ONEBYID query type. See dwControlType member description in [MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola).

### `cControls`

Number of [MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola) structure elements to retrieve. This member must be initialized by the application before calling the [mixerGetLineControls](https://learn.microsoft.com/previous-versions/dd757302(v=vs.85)) function. This member can be 1 only if MIXER_GETLINECONTROLSF_ONEBYID or MIXER_GETLINECONTROLSF_ONEBYTYPE is specified or the value returned in the **cControls** member of the [MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea) structure returned for an audio line. This member cannot be zero. If an audio line specifies that it has no controls, **mixerGetLineControls** should not be called.

### `cbmxctrl`

Size, in bytes, of a single [MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola) structure. The size specified in this member must be at least large enough to contain the base **MIXERCONTROL** structure. The total size, in bytes, required for the buffer pointed to by the **pamxctrl** member is the product of the **cbmxctrl** and **cControls** members of the **MIXERLINECONTROLS** structure.

### `pamxctrl`

Pointer to one or more [MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola) structures to receive the properties of the requested audio line controls. This member cannot be **NULL** and must be initialized before calling the [mixerGetLineControls](https://learn.microsoft.com/previous-versions/dd757302(v=vs.85)) function. Each element of the array of controls must be at least large enough to contain a base **MIXERCONTROL** structure. The **cbmxctrl** member must specify the size, in bytes, of each element in this array. No initialization of the buffer pointed to by this member is required by the application. All members are filled in by the mixer device (including the **cbStruct** member of each **MIXERCONTROL** structure) upon returning successfully.

## See also

[Audio Mixer Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-structures)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)

[MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola)

[MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea)

[mixerGetLineControls](https://learn.microsoft.com/previous-versions/dd757302(v=vs.85))