# MIXERCONTROLDETAILS structure

## Description

The **MIXERCONTROLDETAILS** structure refers to control-detail structures, retrieving or setting state information of an audio mixer control. All members of this structure must be initialized before calling the [mixerGetControlDetails](https://learn.microsoft.com/previous-versions/dd757299(v=vs.85)) and [mixerSetControlDetails](https://learn.microsoft.com/previous-versions/dd757309(v=vs.85)) functions.

## Members

### `cbStruct`

Size, in bytes, of the **MIXERCONTROLDETAILS** structure. The size must be large enough to contain the base **MIXERCONTROLDETAILS** structure. When [mixerGetControlDetails](https://learn.microsoft.com/previous-versions/dd757299(v=vs.85)) returns, this member contains the actual size of the information returned. The returned information will not exceed the requested size, nor will it be smaller than the base **MIXERCONTROLDETAILS** structure.

### `dwControlID`

Control identifier on which to get or set properties.

### `cChannels`

Number of channels on which to get or set control properties. The following values are defined:

| Name | Description |
| --- | --- |
| **0** | Use this value when the control is a MIXERCONTROL_CONTROLTYPE_CUSTOM control. |
| **1** | Use this value when the control is a MIXERCONTROL_CONTROLF_UNIFORM control or when an application needs to get and set all channels as if they were uniform. |
| **MIXERLINE cChannels** | Use this value when the properties for the control are expected on all channels for a line. |

An application cannot specify a value that falls between 1 and the number of channels for the audio line. For example, specifying 2 or 3 for a four-channel line is not valid. This member cannot be 0 for noncustom control types.

This member cannot be 0 for noncustom control types.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hwndOwner`

Handle to the window that owns a custom dialog box for a mixer control. This member is used when the MIXER_SETCONTROLDETAILSF_CUSTOM flag is specified in the [mixerSetControlDetails](https://learn.microsoft.com/previous-versions/dd757309(v=vs.85)) function.

### `DUMMYUNIONNAME.cMultipleItems`

Number of multiple items per channel on which to get or set properties. The following values are defined:

| Name | Description |
| --- | --- |
| **0** | Use this value for all controls except for a MIXERCONTROL_CONTROLF_MULTIPLE or a MIXERCONTROL_CONTROLTYPE_CUSTOM control. |
| **MIXERCONTROL cMultipleItems member** | Use this value when the control class is MIXERCONTROL_CONTROLF_MULTIPLE. |
| **MIXERCONTROLDETAILS hwndOwner member** | Use this value when the control is a MIXERCONTROL_CONTROLTYPE_CUSTOM control and the MIXER_SETCONTROLDETAILSF_CUSTOM flag is specified for the mixerSetControlDetails function. <br><br>In this case, the hwndOwner member overlaps with cMultipleItems, providing the value of the window handle. |

When using a MIXERCONTROL_CONTROLTYPE_CUSTOM control without the MIXERCONTROL_CONTROLTYPE_CUSTOM flag, specify zero for this member.

An application cannot specify any value other than the value specified in the cMultipleItems member of the MIXERCONTROL structure for a MIXERCONTROL_CONTROLF_MULTIPLE control.

### `cbDetails`

Size, in bytes, of one of the following details structures being used:

| Name | Description |
| --- | --- |
| **MIXERCONTROLDETAILS_BOOLEAN** | Boolean value for an audio line control. |
| **MIXERCONTROLDETAILS_LISTTEXT** | List text buffer for an audio line control. For information about the appropriate details structure for a specific control, see [Control Types](https://learn.microsoft.com/windows/desktop/Multimedia/control-types). |
| **MIXERCONTROLDETAILS_SIGNED** | Signed value for an audio line control. |
| **MIXERCONTROLDETAILS_UNSIGNED** | Unsigned value for an audio line control. |

### `paDetails`

Pointer to an array of one or more structures in which properties for
the specified control are retrieved or set.

For MIXERCONTROL_CONTROLF_MULTIPLE controls, the size of this buffer should be the product of the **cChannels**, **cMultipleItems** and **cbDetails** members of the **MIXERCONTROLDETAILS** structure. For controls other than MIXERCONTROL_CONTROLF_MULTIPLE types, the size of this buffer is the product of the **cChannels** and **cbDetails** members of the **MIXERCONTROLDETAILS** structure.

For controls other than MIXERCONTROL_CONTROLF_MULTIPLE types, the size of this buffer is the product of the **cChannels** and **cbDetails** members of the **MIXERCONTROLDETAILS** structure. For controls other than MIXERCONTROL_CONTROLF_MULTIPLE types, the size of this buffer is the product of the **cChannels** and **cbDetails** members of the **MIXERCONTROLDETAILS** structure.

For controls that are MIXERCONTROL_CONTROLF_MULTIPLE types, the array can be treated as a two-dimensional array that is channel major. That is, all multiple items for the left channel are given, then all multiple items for the right channel, and so on.

For controls other than MIXERCONTROL_CONTROLF_MULTIPLE types, each element index is equivalent to the zero-based channel that it affects. That is, paDetails[0] is for the left channel and paDetails[1] is for the right channel.

If the control is a MIXERCONTROL_CONTROLTYPE_CUSTOM control, this member must point to a buffer that is at least large enough to contain the size, in bytes, specified by the cbCustomData member of the MIXERCONTROL structure.

## See also

[Audio Mixer Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-structures)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)

[MIXERCONTROL](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercontrola)

[mixerGetControlDetails](https://learn.microsoft.com/previous-versions/dd757299(v=vs.85))

[mixerSetControlDetails](https://learn.microsoft.com/previous-versions/dd757309(v=vs.85))