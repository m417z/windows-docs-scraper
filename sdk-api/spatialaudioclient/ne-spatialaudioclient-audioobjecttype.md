# AudioObjectType enumeration

## Description

Specifies the type of an [ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject). A spatial audio object can be dynamic, meaning that its spatial properties can change over time, or static, which means that its spatial properties are fixed. There are 17 audio channels to which a static spatial audio object can be assigned, each representing a real or virtualized speaker. The static channel values of the enumeration can be combined as a mask to assign a spatial audio object to multiple channels. All of the enumeration values except for **AudioObjectType_None** and **AudioObjectType_Dynamic** represent static channels.

## Constants

### `AudioObjectType_None:0`

The spatial audio object is not spatialized.

### `AudioObjectType_Dynamic`

The spatial audio object is dynamic. It's spatial properties can be changed over time.

### `AudioObjectType_FrontLeft`

The spatial audio object is assigned the front left channel. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_FRONT_LEFT.

### `AudioObjectType_FrontRight`

The spatial audio object is assigned the front right channel. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_FRONT_RIGHT.

### `AudioObjectType_FrontCenter`

The spatial audio object is assigned the front center channel. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_FRONT_CENTER.

### `AudioObjectType_LowFrequency`

The spatial audio object is assigned the low frequency channel. Because this channel is not spatialized, it does not count toward the system resource limits for spatialized audio objects. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_LOW_FREQUENCY.

### `AudioObjectType_SideLeft`

The spatial audio object is assigned the side left channel. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_SIDE_LEFT.

### `AudioObjectType_SideRight`

The spatial audio object is assigned the side right channel. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_SIDE_RIGHT.

### `AudioObjectType_BackLeft`

The spatial audio object is assigned the back left channel. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_BACK_LEFT.

### `AudioObjectType_BackRight`

The spatial audio object is assigned the back right channel. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_BACK_RIGHT.

### `AudioObjectType_TopFrontLeft`

The spatial audio object is assigned the top front left channel. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_TOP_FRONT_LEFT.

### `AudioObjectType_TopFrontRight`

The spatial audio object is assigned the top front right channel. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_TOP_FRONT_RIGHT.

### `AudioObjectType_TopBackLeft`

The spatial audio object is assigned the top back left channel. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_TOP_BACK_LEFT.

### `AudioObjectType_TopBackRight`

The spatial audio object is assigned the top back right channel. The equivalent channel mask of DirectShow's [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)) enumeration is SPEAKER_TOP_BACK_RIGHT.

### `AudioObjectType_BottomFrontLeft`

The spatial audio object is assigned the bottom front left channel.

### `AudioObjectType_BottomFrontRight`

The spatial audio object is assigned the bottom front right channel.

### `AudioObjectType_BottomBackLeft`

The spatial audio object is assigned the bottom back left channel.

### `AudioObjectType_BottomBackRight`

The spatial audio object is assigned the bottom back right channel.

### `AudioObjectType_BackCenter`

The spatial audio object is assigned the back center channel.

### `AudioObjectType_DirectLeft`

Equivalent to **SPEAKER_FRONT_LEFT** without any virtualization. Introduced in Windows 11, version 24H2.

### `AudioObjectType_DirectRight`

Equivalent to **SPEAKER_FRONT_RIGHT** without any virtualization. Introduced in Windows 11, version 24H2.