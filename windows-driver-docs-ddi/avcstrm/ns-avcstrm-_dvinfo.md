# _DVINFO structure

## Description

The DVINFO structure describes a DV stream format including its default streaming source information and stream control information.

## Members

### `dwDVAAuxSrc`

Specifies the Audio Auxiliary Data Source Pack for the first audio block (first 5 DV DIF sequences for 525-60 systems or 6 DV DIF sequences for 625-50 systems) of a frame. A DIF sequence is a data block that contains 150 DIF blocks. A DIF block consists of 80 bytes. The Audio Auxiliary Data Source Pack is defined in section D.7.1 of Part 2, Annex D, "The Pack Header Table and Contents of Packs" of the *Specification of Consumer-use Digital VCRs*.

### `dwDVAAuxCtl`

Specifies the Audio Auxiliary Data Source Control Pack for the first audio block of a frame. The Audio Auxiliary Data Control Pack is defined in section D.7.2 of Part 2, Annex D, "The Pack Header Table and Contents of Packs" of the *Specification of Consumer-use Digital VCRs*.

### `dwDVAAuxSrc1`

Specifies the Audio Auxiliary Data Source Pack for the second audio block (second 5 DV DIF sequences for 525-60 systems or 6 DV DIF sequences for 625-50 systems) of a frame.

### `dwDVAAuxCtl1`

Specifies the Audio Auxiliary Data Source Control Pack for the second audio block of a frame.

### `dwDVVAuxSrc`

Specifies the Video Auxiliary Data Source Pack as defined in section D.8.1 of Part 2, Annex D, "The Pack Header Table and Contents of Packs" of the *Specification of Consumer-use Digital VCRs*.

### `dwDVVAuxCtl`

Specifies the Video Auxiliary Data Source Control Pack as defined in section D.8.2 of Part 2, Annex D, "The Pack Header Table and Contents of Packs" of the *Specification of Consumer-use Digital VCRs*.

### `dwDVReserved`

Reserved. This must be set to 0. Do not use this.