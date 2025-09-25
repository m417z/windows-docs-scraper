# IQueryCancelAutoPlay::AllowAutoPlay

## Description

Determines whether to play media inserted by a user and if so using what restrictions.

## Parameters

### `pszPath` [in]

Type: **LPCWSTR**

The drive letter in the form **D:\\**

### `dwContentType` [in]

Type: **DWORD**

The type of content as specified by the following flags.

#### ARCONTENT_AUTORUNINF (0x00000002)

Use the Autorun.inf file. This is the traditional AutoRun behavior.

#### ARCONTENT_AUDIOCD (0x00000004)

AutoRun audio CDs.

#### ARCONTENT_DVDMOVIE (0x00000008)

AutoRun DVDs.

#### ARCONTENT_BLANKCD (0x00000010)

AutoPlay blank CD-Rs and CD-RWs.

#### ARCONTENT_BLANKDVD (0x00000020)

AutoPlay blank DVD-Rs and DVD-RAMs.

#### ARCONTENT_UNKNOWNCONTENT (0x00000040)

AutoRun if the media is formatted and the content does not fall under a type covered by one of the other flags.

#### ARCONTENT_AUTOPLAYPIX (0x00000080)

AutoPlay if the content consists of file types defined as pictures, such as .bmp and .jpg files.

#### ARCONTENT_AUTOPLAYMUSIC (0x00000100)

AutoPlay if the content consists of file types defined as music, such as MP3 files.

#### ARCONTENT_AUTOPLAYVIDEO (0x00000200)

AutoPlay if the content consists of file types defined as video files.

#### ARCONTENT_VCD (0x00000400)

**Introduced in Windows Vista**. AutoPlay video CDs (VCDs).

#### ARCONTENT_SVCD (0x00000800)

**Introduced in Windows Vista**. AutoPlay Super Video CD (SVCD) media.

#### ARCONTENT_DVDAUDIO (0x00001000)

**Introduced in Windows Vista**. AutoPlay DVD-Audio media.

#### ARCONTENT_BLANKBD (0x00002000)

AutoPlay blank recordable high definition DVD media in the Blu-ray Disc™ format (BD-R or BD-RW). Note: Prior to Windows 7, this value was defined to specify non-recordable media in the HD DVD format.

#### ARCONTENT_BLURAY (0x00004000)

**Introduced in Windows Vista**. AutoPlay high definition DVD media in the Blu-ray Disc™ format.

#### ARCONTENT_CAMERASTORAGE (0x00008000)

**Introduced in Windows 8**.

#### ARCONTENT_CUSTOMEVENT (0x00010000)

**Introduced in Windows 8**.

#### ARCONTENT_NONE (0x00000000)

**Introduced in Windows Vista**. AutoPlay empty but formatted media.

#### ARCONTENT_MASK (0x0001FFFE)

**Introduced in Windows Vista**. A mask that denotes valid ARCONTENT flag values for media types. This mask does not include ARCONTENT_PHASE values.

#### ARCONTENT_PHASE_UNKNOWN (0x00000000)

**Introduced in Windows Vista**. AutoPlay is searching the media. The phase of the search (presniff, sniffing, or final) is unknown.

#### ARCONTENT_PHASE_PRESNIFF (0x10000000)

**Introduced in Windows Vista**. The contents of the media are known before the media is searched, due to the media type; for instance, audio CDs and DVD movies.

#### ARCONTENT_PHASE_SNIFFING (0x20000000)

**Introduced in Windows Vista**. AutoPlay is currently searching the media. Any results reported during this phase should be considered a partial list as more content types might still be found.

#### ARCONTENT_PHASE_FINAL (0x40000000)

**Introduced in Windows Vista**. AutoPlay has finished searching the media. Results reported are final.

#### ARCONTENT_PHASE_MASK (0x70000000)

**Introduced in Windows Vista**. A mask that denotes valid ARCONTENT_PHASE values.

### `pszLabel` [in]

Type: **LPCWSTR**

The media label.

### `dwSerialNumber` [in]

Type: **DWORD**

The media serial number.

## Return value

Type: **HRESULT**

Returns S_OK to allow AutoRun or S_FALSE to cancel AutoRun.

## Remarks

Applications register an instance of the [IQueryCancelAutoPlay](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iquerycancelautoplay) interface in the running object table (ROT). Before the Shell starts AutoRun or AutoPlay, when the user inserts new media, it checks the ROT for a component implementing **IQueryCancelAutoPlay**. If it finds one, the Shell calls that implementation's **IQueryCancelAutoPlay::AllowAutoPlay** method to determine whether it should proceed, and using what restrictions.

Upon presentation of media, the Shell searches the ROT for a component implementing [IQueryCancelAutoPlay](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iquerycancelautoplay). If one is found, the class identifier (CLSID) of that component's moniker is extracted. The presence of a ROT registration informs the Shell that the component might want to cancel AutoRun or AutoPlay. For confirmation, the Shell must also find a registry key for that same CLSID at the following location:

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Microsoft
         Windows
            Current Version
               Explorer
                  AutoplayHandlers
                     CancelAutoplay
                        CLSID
                           The component's CLSID
```

This value is added by the application or hardware, usually at installation time. It isn't assigned a data value.

**Note** The CLSID entered as a value under this key should not be encased in curly brackets.