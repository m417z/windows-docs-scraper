# IDirectMusicSynth::Download

## Description

The `Download` method downloads a wave or instrument definition to the synthesizer.

## Parameters

### `phDownload`

Output pointer for the download handle. This parameter points to a caller-allocated variable into which the method writes a handle identifying the download data. The caller uses this handle later to unload the data.

### `pvData`

Pointer to a continuous memory segment containing download data. For an overview of the data format, see the description of low-level DLS in the DirectMusic section of the Microsoft Windows SDK documentation.

### `pbFree`

Output pointer for a status value indicating whether the memory for the download data can be freed. This parameter points to a caller-allocated variable into which the method writes a Boolean value indicating whether the caller can free the storage pointed to by *pvData*. If **TRUE**, the application can safely free the memory after the return. If **FALSE**, the caller must keep the memory pointed to by *pvData* allocated until it is unloaded.

## Return value

`Download` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Indicates that one of the pointers is invalid. |
| **E_FAIL** | Indicates that the method is unable to download the data. |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not open or not properly configured. |
| **DMUS_E_NOTMONO** | Indicates that the wave chunk has more than one interleaved channel. |
| **DMUS_E_BADARTICULATION** | Indicates a bad articulation chunk or link. |
| **DMUS_E_BADINSTRUMENT** | Indicates a bad instrument chunk or link. |
| **DMUS_E_BADWAVELINK** | Indicates a bad link to the wave download data. |
| **DMUS_E_NOARTICULATION** | Indicates that the region in instrument has neither global nor local articulation. |
| **DMUS_E_NOTPCM** | Indicates that the wave data is not PCM. |
| **DMUS_E_BADWAVE** | Indicates that the wave header is corrupt. |
| **DMUS_E_BADOFFSETTABLE** | Indicates that the offset table contains errors. |
| **DMUS_E_UNKNOWNDOWNLOAD** | Indicates that the download data is neither instrument nor wave. |

## Remarks

The data is stored in a continuous chunk of memory, pointed to by *pvData*. However, at the head of the chunk are two data structures, which define the nature of the data to follow. These are the DMUS_DOWNLOADINFO and DMUS_OFFSETTABLE structures (described in Microsoft Windows SDK documentation). DMUS_DOWNLOADINFO is a header that describes how to parse the data, including its size and intention (wave or instrument.) DMUS_OFFSETTABLE provides a set of byte offsets into the data segment that follows. All parsing through the data is managed through this table.

Whenever a structure in the data references another structure, it describes it by an index into the offset table. The offset table then converts it into a byte offset into the data. This allows the synthesizer to do bounds checking on all references, making the implementation more robust. In kernel-mode implementations, the driver can make its own private copy of the offset table, and so ensure that an application in user mode cannot alter its referencing and cause a crash.

The **dwDLType** member of DMUS_DOWNLOADINFO specifies the type of data being downloaded. It is set to DMUS_DOWNLOADINFO_INSTRUMENT for an instrument, DMUS_DOWNLOADINFO_WAVE for a wave. As new data types emerge, identifiers will be allocated for them. **dwDLId** holds a unique 32-bit identifier for the object. This identifier is used to connect objects together. In the case of level-1 DLS, the identifier is used to connect waves to instruments. The **dwNumOffsetTableEntries** member of DMUS_DOWNLOADINFO describes the number of entries in the DMUS_OFFSETTABLE structure, which follows. Finally, the **cbSize** member specifies the total size of the memory chunk that consists of DMUS_DOWNLOADINFO + DMUS_OFFSETTABLE + data chunk.

Note that the download memory is always padded with an extra 32 bytes. This allows synthesizer implementations that require additional padding at the end of loops for multipoint interpolation to fill the space after the end of a wave chunk with additional data, up to 32 bytes. This additional padding is reflected by **cbSize**.

Depending on the synthesizer implementation, the synthesizer might decide to use the memory in the download chunk. After all, if enough memory has been allocated to store a wave, that same memory can be used by the synthesizer to store it for playback. So the synthesizer has the option of retaining the memory, and it returns its decision in the *pbFree* parameter. If it does keep the memory, then the caller must not free it. Later, the [IDirectMusicSynth::Unload](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-unload) method has a callback mechanism to handle asynchronous freeing of the memory once the unload request has been made.

## See also

[IDirectMusicSynth](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynth)

[IDirectMusicSynth::Unload](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-unload)