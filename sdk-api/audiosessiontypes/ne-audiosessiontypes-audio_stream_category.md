# AUDIO_STREAM_CATEGORY enumeration

## Description

Specifies the category of an audio stream.

## Constants

### `AudioCategory_Other`

Other audio stream.

### `AudioCategory_ForegroundOnlyMedia`

Media that will only stream when the app is in the foreground. This enumeration value has been deprecated. For more information, see the Remarks section.

### `AudioCategory_BackgroundCapableMedia`

Media that can be streamed when the app is in the background. This enumeration value has been deprecated. For more information, see the Remarks section.

### `AudioCategory_Communications`

Real-time communications, such as VOIP or chat.

### `AudioCategory_Alerts`

Alert sounds.

### `AudioCategory_SoundEffects`

Sound effects.

### `AudioCategory_GameEffects`

Game sound effects.

### `AudioCategory_GameMedia`

Background audio for games.

### `AudioCategory_GameChat`

Game chat audio. Similar to **AudioCategory_Communications** except that **AudioCategory_GameChat** will not attenuate other streams.

### `AudioCategory_Speech`

Speech.

### `AudioCategory_Movie`

Stream that includes audio with dialog.

### `AudioCategory_Media`

Stream that includes audio without dialog.

### `AudioCategory_FarFieldSpeech`

Media is audio captured with the intent of capturing voice sources located in the ‘far field’. (Far away from the microphone.)

### `AudioCategory_UniformSpeech`

Media is captured audio that requires consistent speech processing for the captured audio stream across all Windows devices. Used by applications that process speech data using machine learning algorithms.

### `AudioCategory_VoiceTyping`

Media is audio captured with the intent of enabling dictation or typing by voice.

## Remarks

Note that only a subset of the audio stream categories are valid for certain stream types.

| Stream type | Valid categories |
| --- | --- |
| Render stream | All categories are valid. |
| Capture stream | AudioCategory_Communications, AudioCategory_Speech, AudioCategory_Other |
| Loopback stream | AudioCategory_Other |

Games should categorize their music streams as **AudioCategory_GameMedia** so that game music mutes automatically if another application plays music in the background. Music or video applications should categorize their streams as **AudioCategory_Media** or **AudioCategory_Movie** so they will take priority over **AudioCategory_GameMedia** streams. Game audio for in-game cinematics or cutscenes, when the audio is premixed or for creative reasons should take priority over background audio, should also be categorized as **Media** or **Movie**.

The values **AudioCategory_ForegroundOnlyMedia** and **AudioCategory_BackgroundCapableMedia** are deprecated. For Windows Store apps, these values will continue to function the same when running on Windows 10 as they did on Windows 8.1. Attempting to use these values in a Universal Windows Platform (UWP) app, will result in compilation errors and an exception at runtime. Using these values in a Windows desktop application built with the Windows 10 SDK the will result in a compilation error.

## See also

[Core Audio Enumerations](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-enumerations)