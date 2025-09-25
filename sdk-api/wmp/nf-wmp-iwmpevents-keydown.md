# IWMPEvents::KeyDown

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **KeyDown** event occurs when a key is pressed.

## Parameters

### `nKeyCode` [in]

Specifies which physical key is pressed. For possible values, see the Remarks section.

### `nShiftState` [in]

A bitfield with the least significant bits corresponding to the SHIFT key (bit 0), the CTRL key (bit 1), and the ALT key (bit 2). These bits correspond to the values 1, 2, and 4, respectively. The shift argument indicates the state of these keys. Some, all, or none of the bits can be set, indicating that some, all, or none of the keys are pressed.

## Remarks

The *nKeyCode* argument specifies a physical key. The following tables show the possible values for the major keys on a standard keyboard.

Values for the main keys.

| Key | Value |
| --- | --- |
| A-Z | 65-90 |
| 0-9 | 48-56 |
| F1-F12 | 112-123 |
| ESC | 27 |
| TAB | 9 |
| CAPS LOCK | 20 |
| SHIFT (left or right) | 16 |
| CTRL (left or right) | 17 |
| ALT (left or right) | 18 |
| SPACE | 32 |
| BACKSPACE | 8 |
| ENTER | 13 |
| Windows logo key, left | 91 |
| Windows logo key, right | 92 |
| Application key | 93 |

Values for the number pad keys.

| Key | Value |
| --- | --- |
| 0-9 | 96-105 |
| NUM LOCK | 144 |
| DIVIDE (/) | 111 |
| MULTIPLY (*) | 106 |
| SUBTRACT (-) | 109 |
| ADD (+) | 107 |
| SEPARATOR (Enter) | 108 |
| DECIMAL (.) | 110 |

Values for the navigation keys.

| Key | Value |
| --- | --- |
| INSERT | 45 |
| DELETE | 46 |
| HOME | 36 |
| END | 35 |
| PAGE UP | 33 |
| PAGE DOWN | 34 |
| UP ARROW | 38 |
| DOWN ARROW | 40 |
| LEFT ARROW | 37 |
| RIGHT ARROW | 39 |

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)