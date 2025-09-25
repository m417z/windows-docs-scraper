# IWMPEvents::ScriptCommand

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **ScriptCommand** event occurs when a synchronized command or URL is received.

## Parameters

### `scType` [in]

Specifies the type of script command.

### `Param` [in]

Specifies the script command.

## Remarks

Commands can be embedded along with the audio, video, or other data within a Windows Media file. The commands are comprised of a pair of Unicode strings associated with a designated time in the stream.

When playback reaches the time associated with the command, the Windows Media Player control sends a **ScriptCommand** event with two parameters. One parameter specifies the type of command being sent. The other parameter specifies the command. The type of parameter is used to determine how the command parameter is processed. Any type of command can be embedded in a Windows Media file to be handled by the **ScriptCommand** event.

The following table lists script command types that are processed automatically by Windows Media Player.

| Type | Description |
| --- | --- |
| CAPTION | The control displays the associated text in the DIV specified by **IWMPClosedCaption::get_captioningID**. |
| EVENT | Tells the control to execute instructions defined for the specified event. |
| FILENAME | The control resets its **URL** property, attempts to open the specified file, and begins playing the new stream immediately. |
| OPENEVENT | Buffers the associated EVENT command for timely execution of the EVENT script. |
| SYNCHRONIZEDLYRICLYRIC | The *Param* parameter contains the synchronized lyric text. Windows Media Player displays the lyric text in the closed caption area of the **Now Playing** feature. |
| TEXT | The control displays the associated text in the DIV specified by **IWMPClosedCaption::get_captioningID**. |
| URL | The control automatically opens the URL specified using the default Internet browser if the **IWMPSettings::put_invokeURLs** method has been called. |

You can embed any other type of command as long as you provide reciprocal code to handle the command. Unknown commands are ignored by the Windows Media Player control, but they are still handed off to the **ScriptCommand** event.

The **ScriptCommand** event is not called if the file is being scanned in fast forward or fast reversed mode.

The value of event parameters is specified by Windows Media Player. It can be accessed or passed to a method in an imported JScript file by using the parameter name. This parameter name must be typed exactly as shown, including capitalization.

URL commands received by the Windows Media Player control are invoked automatically in the user's default Web browser if the **IWMPSettings::put_baseURL** method has been called. You can use the **IWMPSettings::put_defaultFrame** property to specify the target frame in which the webpage appears.

The URL sent to Windows Media Player is processed relative to the base URL specified by the **IWMPSettings::get_invokeURLs** method. The base URL is concatenated with the relatively specified URL, resulting in a fully specified URL that is passed as the command parameter by the **ScriptCommand** event.

The Windows Media Player control always processes incoming URL commands in the following manner:

1. A URL command is received.
2. **IWMPSettings::put_baseURL** is used to create a full URL from the relative URL specified in the script command.
3. **ScriptCommand** is called.
4. After **ScriptCommand** returns, **IWMPSettings::get_invokeURLs** is checked.
5. If **IWMPSettings::get_invokeURLs** is true and the command is a URL command, the specified URL is invoked. If **IWMPSettings::get_invokeURLs** is false or the command is not a URL command, the command is ignored.

When authoring a Windows Media file, you can specify which frame the new URL is displayed in by concatenating two ampersand (&) characters and the name of the frame in the parameter field. The following example specifies that the URL http://myweb/mypage.html must be launched in the frame called myframe.

```cpp

scType = "URL"
Param = http://myweb/mypage.html&&myframe

```

## See also

[IWMPClosedCaption::get_captioningId](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpclosedcaption-get_captioningid)

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)

[IWMPSettings::get_invokeURLs](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-get_invokeurls)

[IWMPSettings::put_baseURL](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_baseurl)

[IWMPSettings::put_defaultFrame](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_defaultframe)

[IWMPSettings::put_invokeURLs](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-put_invokeurls)