# IWMWriter::BeginWriting

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **BeginWriting** method initializes the writing process.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | There is not enough available memory. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |
| **NS_E_AUDIO_CODEC_ERROR** | An error occurred in the audio codec. |
| **NS_E_AUDIO_CODEC_NOT_INSTALLED** | The required audio codec is not available. |
| **NS_E_DRM_RIV_TOO_SMALL** | A more recent content revocation list is needed. |
| **NS_E_INVALID_OUTPUT_FORMAT** | The output format is not valid. |
| **NS_E_VIDEO_CODEC_ERROR** | An error occurred in the video codec. |
| **NS_E_VIDEO_CODEC_NOT_INSTALLED** | The required video codec is not available. |

## Remarks

The **BeginWriting** method must be called before any samples are written. This method does not actually start writing, but initializes the process. Between this call and the call to [EndWriting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-endwriting) there can be no configuration changes to the writer. The **EndWriting** method must be called to cleanly end the writing of the samples.

The following operations can be performed only before calling **BeginWriting**:

* Setting the profile with [SetProfile](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-setprofile)
* Setting the output filename (if using [IWMWriter::SetOutputFilename](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-setoutputfilename))
* Setting an attribute with [IWMHeaderInfo::SetAttribute](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-setattribute)
* [Marker](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) operations ([IWMHeaderInfo::GetMarkerCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getmarkercount), [GetMarker](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getmarker), [AddMarker](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-addmarker), and [RemoveMarker](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-removemarker), although **AddMarker** is not implemented on the writer and the rest aren't useful if there are no markers)
* Calling [IWMWriter::SetInputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-setinputprops) with a **NULL**[IWMInputMediaProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwminputmediaprops) parameter to indicate that the input stream will be written using [WriteStreamSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-writestreamsample).
* Header Script operations ([IWMHeaderInfo::GetScriptCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getscriptcount), [GetScript](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getscript), [AddScript](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-addscript), and [RemoveScript](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-removescript))
* Codec info operations ([IWMHeaderInfo2::GetCodecInfoCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo2-getcodecinfocount) and [GetCodecInfo](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo2-getcodecinfo))
* [IWMWriterPostView::SetPostViewProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterpostview-setpostviewprops)

The following methods can be called only after a profile has been set and before calling **BeginWriting**:

* [IWMHeaderInfo::GetAttributeCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getattributecount)
* [IWMHeaderInfo::GetAttributeByIndex](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getattributebyindex)
* [IWMHeaderInfo::GetAttributeByName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getattributebyname)
* [IWMWriterAdvanced2::SetInputSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced2-setinputsetting)

Note: [SetInputSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced2-setinputsetting) can be called after **BeginWriting** for g_wszDeinterlaceMode, g_wszInitialPatternForInverseTelecine, g_wszInterlacedCoding, and g_wszJPEGCompressionQuality.

The following operations can be performed any time after a profile has been set:

* Any postview operations except for **SetPostViewProps**
* [IWMWriter::SetInputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-setinputprops) except when passing in a **NULL**[IWMInputMediaProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwminputmediaprops) parameter.
* [IWMWriter::GetInputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-getinputprops)
* [IWMWriter::GetInputFormatCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-getinputformatcount)
* [IWMWriter::GetInputFormat](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-getinputformat)

The following operations can be performed only after calling **BeginWriting**:

* Allocating samples with [IWMWriter::AllocateSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-allocatesample)
* Writing samples with [IWMWriter::WriteSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-writesample) and [IWMWriterAdvanced::WriteStreamSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-writestreamsample)
* [IWMWriter::EndWriting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-endwriting)

The following operations can be performed at any time:

* Adding and removing a sink with [IWMWriterAdvanced::AddSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-addsink) and [IWMWriterAdvanced::RemoveSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-removesink)
* [IWMWriterAdvanced::SetLiveSource](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-setlivesource)
* [IWMWriterAdvanced::IsRealTime](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-isrealtime)
* [IWMWriterAdvanced::GetWriterTime](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getwritertime) (although it won't return meaningful values)
* [IWMWriterAdvanced::GetStatistics](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getstatistics)
* [IWMWriterAdvanced::SetSyncTolerance](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-setsynctolerance)
* [IWMWriterAdvanced::GetSyncTolerance](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getsynctolerance)

#### Examples

The following example code outlines how to set up a writer and send output both to a network sink and an archive file.

```cpp

IWMWriter *             pWriter = NULL;
IWMWriterAdvanced *     pWriterAdvanced = NULL;
IWMWriterFileSink2 *    pWriterFileSink = NULL;
IWMWriterNetworkSink2 * pWriterNetworkSink = NULL;
HRESULT                 hr = S_OK;
DWORD                   dwPort;

// Do everything in a dummy loop for easy error-handling.

do
{
    // Create the basic objects.

    hr = WMCreateWriter( &pWriter );
    if( FAILED( hr ) )
    {
        break;
    }

    hr = WMCreateWriterFileSink( &pWriterFileSink );
    if( FAILED( hr ) )
    {
        break;
    }

    hr = WMCreateWriterNetworkSink( &pWriterNetworkSink );
    if( FAILED( hr ) )
    {
        break;
    }

    // Retrieve a pointer to an IWMWriterAdvanced interface and add the sinks.

    hr = pWriter->QueryInterface( IID_IWMWriterAdvanced, (void **)&pWriterAdvanced );
    if( FAILED( hr ) )
    {
        break;
    }

    hr = pWriterAdvanced->AddSink( pWriterFileSink );
    if( FAILED( hr ) )
    {
        break;
    }

    hr = pWriterAdvanced->AddSink( pWriterNetworkSink );
    if( FAILED( hr ) )
    {
        break;
    }

    hr = pWriterFileSink->Open( L"Archive file name" );
    if( FAILED( hr ) )
    {
        break;
    }

    // Setting the port number to zero enables the SDK to select an
    // appropriate port number.
    dwPort = 0;
    hr = pWriterNetworkSink->Open( &dwPort );
    if( FAILED( hr ) )
    {
        break;
    }

    hr = pWriter->BeginWriting();
    if( FAILED( hr ) )
    {
        break;
    }

    // Code to send data to the writer goes here (not shown).

    // Close both sinks.
    hr = pWriterFileSink->Close();
    if( FAILED( hr ) )
    {
        break;
    }

    hr = pWriterNetworkSink->Close();
    if( FAILED( hr ) )
    {
        break;
    }

    hr = pWriter-> EndWriting();
    if( FAILED( hr ) )
    {
        break;
    }
}
while( FALSE );

// Clean up.

if ( pWriter )
{
    pWriter->Release();
}
if ( pWriterAdvanced )
{
    pWriterAdvanced->Release();
}
if ( pWriterFileSink )
{
    pWriterFileSink->Release();
}
if ( pWriterNetworkSink )
{
    pWriterNetworkSink->Release();
}

```

## See also

[IWMWriter Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriter)

[IWMWriter::EndWriting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-endwriting)