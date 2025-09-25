# D3DWDDM2_0DDI_VIDEODEVICEFUNCS structure

## Description

The **D3DWDDM2_0DDI_VIDEODEVICEFUNCS** structure specifies the video function table for the Direct3D driver device object. This structure is used by WDDM 2.0 and later drivers.

The driver must support the WDDM 2.0 version of the user-mode DDI. When the DDI is supported, the runtime will call [**PFND3D10DDI_RETRIEVESUBOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_retrievesubobject) to retrieve the **D3DWDDM2_0DDI_VIDEODEVICEFUNCS** video device functions.

## Members

### `pfnGetVideoDecoderProfileCount`

The entry point for the driver's [**GetVideoDecoderProfileCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderprofilecount) function.

### `pfnGetVideoDecoderProfile`

The entry point for the driver's [**GetVideoDecoderProfile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderprofile) function.

### `pfnCheckVideoDecoderFormat`

The entry point for the driver's [**CheckVideoDecoderFormat**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_checkvideodecoderformat) function.

### `pfnGetVideoDecoderConfigCount`

The entry point for the driver's [**GetVideoDecoderConfigCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderconfigcount) function.

### `pfnGetVideoDecoderConfig`

The entry point for the driver's [**GetVideoDecoderConfig**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderconfig) function.

### `pfnGetVideoDecoderBufferTypeCount`

The entry point for the driver's [**GetVideoDecoderBufferTypeCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderbuffertypecount) function.

### `pfnGetVideoDecoderBufferInfo`

The entry point for the driver's [**GetVideoDecoderBufferInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideodecoderbufferinfo) function.

### `pfnCalcPrivateVideoDecoderSize`

The entry point for the driver's [**CalcPrivateVideoDecoderSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideodecodersize) function.

### `pfnCreateVideoDecoder`

The entry point for the driver's [**CreateVideoDecoder**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoder) function.

### `pfnDestroyVideoDecoder`

The entry point for the driver's [**DestroyVideoDecoder**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroyvideodecoder) function.

### `pfnVideoDecoderExtension`

The entry point for the driver's [**VideoDecoderExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderextension) function.

### `pfnVideoDecoderBeginFrame`

The entry point for the driver's [**VideoDecoderBeginFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderbeginframe) function.

### `pfnVideoDecoderEndFrame`

The entry point for the driver's [**VideoDecoderEndFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderendframe) function.

### `pfnVideoDecoderSubmitBuffers`

The entry point for the driver's [**VideoDecoderSubmitBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecodersubmitbuffers) function.

### `pfnCalcPrivateVideoProcessorEnumSize`

The entry point for the driver's [**CalcPrivateVideoProcessorEnumSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessorenumsize) function.

### `pfnCreateVideoProcessorEnum`

The entry point for the driver's [**CreateVideoProcessorEnum**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum) function.

### `pfnDestroyVideoProcessorEnum`

The entry point for the driver's [**DestroyVideoProcessorEnum**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroyvideoprocessorenum) function.

### `pfnCheckVideoProcessorFormat`

The entry point for the driver's [**CheckVideoProcessorFormat**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_checkvideoprocessorformat) function.

### `pfnGetVideoProcessorCaps`

The entry point for the driver's [**GetVideoProcessorCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcaps) function.

### `pfnGetVideoProcessorRateConversionCaps`

The entry point for the driver's [**GetVideoProcessorRateConversionCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorrateconversioncaps) function.

### `pfnGetVideoProcessorCustomRate`

The entry point for the driver's [**GetVideoProcessorCustomRate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorcustomrate) function.

### `pfnGetVideoProcessorFilterRange`

The entry point for the driver's [**GetVideoProcessorFilterRange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorfilterrange) function.

### `pfnCalcPrivateVideoProcessorSize`

The entry point for the driver's [**CalcPrivateVideoProcessorSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessorsize) function.

### `pfnCreateVideoProcessor`

The entry point for the driver's [**CreateVideoProcessor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessor) function.

### `pfnDestroyVideoProcessor`

The entry point for the driver's [**DestroyVideoProcessor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroyvideoprocessor) function.

### `pfnVideoProcessorSetOutputTargetRect`

The entry point for the driver's [**VideoProcessorSetOutputTargetRect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputtargetrect) function.

### `pfnVideoProcessorSetOutputBackgroundColor`

The entry point for the driver's [**VideoProcessorSetOutputBackgroundColor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputbackgroundcolor) function.

### `pfnVideoProcessorSetOutputColorSpace`

The entry point for the driver's [**VideoProcessorSetOutputColorSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputcolorspace) function.

### `pfnVideoProcessorSetOutputAlphaFillMode`

The entry point for the driver's [**VideoProcessorSetOutputAlphaFillMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputalphafillmode) function.

### `pfnVideoProcessorSetOutputConstriction`

The entry point for the driver's [**VideoProcessorSetOutputConstriction**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputconstriction) function.

### `pfnVideoProcessorSetOutputStereoMode`

The entry point for the driver's [**VideoProcessorSetOutputStereoMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputstereomode) function.

### `pfnVideoProcessorSetOutputExtension`

The entry point for the driver's [**VideoProcessorSetOutputExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputextension) function.

### `pfnVideoProcessorGetOutputExtension`

The entry point for the driver's [**VideoProcessorGetOutputExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorgetoutputextension) function.

### `pfnVideoProcessorSetStreamFrameFormat`

The entry point for the driver's [**VideoProcessorSetStreamFrameFormat**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamframeformat) function.

### `pfnVideoProcessorSetStreamColorSpace`

The entry point for the driver's [**VideoProcessorSetStreamColorSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamcolorspace) function.

### `pfnVideoProcessorSetStreamOutputRate`

The entry point for the driver's [**VideoProcessorSetStreamOutputRate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamoutputrate) function.

### `pfnVideoProcessorSetStreamSourceRect`

The entry point for the driver's [**VideoProcessorSetStreamSourceRect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamsourcerect) function.

### `pfnVideoProcessorSetStreamDestRect`

The entry point for the driver's [**VideoProcessorSetStreamDestRect**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamdestrect) function.

### `pfnVideoProcessorSetStreamAlpha`

The entry point for the driver's [**VideoProcessorSetStreamAlpha**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamalpha) function.

### `pfnVideoProcessorSetStreamPalette`

The entry point for the driver's [**VideoProcessorSetStreamPalette**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreampalette) function.

### `pfnVideoProcessorSetStreamPixelAspectRatio`

The entry point for the driver's [**VideoProcessorSetStreamPixelAspectRatio**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreampixelaspectratio) function.

### `pfnVideoProcessorSetStreamLumaKey`

The entry point for the driver's [**VideoProcessorSetStreamLumaKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamlumakey) function.

### `pfnVideoProcessorSetStreamStereoFormat`

The entry point for the driver's [**VideoProcessorSetStreamStereoFormat**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamstereoformat) function.

### `pfnVideoProcessorSetStreamAutoProcessingMode`

The entry point for the driver's [**VideoProcessorSetStreamAutoProcessingMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamautoprocessingmode) function.

### `pfnVideoProcessorSetStreamFilter`

The entry point for the driver's [**VideoProcessorSetStreamFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamfilter) function.

### `pfnVideoProcessorSetStreamExtension`

The entry point for the driver's [**VideoProcessorSetStreamExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamextension) function.

### `pfnVideoProcessorGetStreamExtension`

The entry point for the driver's [**VideoProcessorGetStreamExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorgetstreamextension) function.

### `pfnVideoProcessorBlt`

The entry point for the driver's [**VideoProcessorBlt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt) function.

### `pfnCalcPrivateVideoDecoderOutputViewSize`

The entry point for the driver's [**CalcPrivateVideoDecoderOutputViewSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideodecoderoutputviewsize) function.

### `pfnCreateVideoDecoderOutputView`

The entry point for the driver's [**CreateVideoDecoderOutputView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideodecoderoutputview) function.

### `pfnDestroyVideoDecoderOutputView`

The entry point for the driver's [**DestroyVideoDecoderOutputView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroyvideodecoderoutputview) function.

### `pfnCalcPrivateVideoProcessorInputViewSize`

The entry point for the driver's [**CalcPrivateVideoProcessorInputViewSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessorinputviewsize) function.

### `pfnCreateVideoProcessorInputView`

The entry point for the driver's [**CreateVideoProcessorInputView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorinputview) function.

### `pfnDestroyVideoProcessorInputView`

The entry point for the driver's [**DestroyVideoProcessorInputView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroyvideoprocessorinputview) function.

### `pfnCalcPrivateVideoProcessorOutputViewSize`

The entry point for the driver's [**CalcPrivateVideoProcessorOutputViewSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatevideoprocessoroutputviewsize) function.

### `pfnCreateVideoProcessorOutputView`

The entry point for the driver's [**CreateVideoProcessorOutputView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessoroutputview) function.

### `pfnDestroyVideoProcessorOutputView`

The entry point for the driver's [**DestroyVideoProcessorOutputView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroyvideoprocessoroutputview) function.

### `pfnVideoProcessorInputViewReadAfterWriteHazard`

The entry point for the driver's [**VideoProcessorInputViewReadAfterWriteHazard**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorinputviewreadafterwritehazard) function.

### `pfnGetContentProtectionCaps`

The entry point for the driver's [**GetContentProtectionCaps**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcontentprotectioncaps) function.

### `pfnGetCryptoKeyExchangeType`

The entry point for the driver's [**GetCryptoKeyExchangeType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcryptokeyexchangetype) function.

### `pfnCalcPrivateCryptoSessionSize`

The entry point for the driver's [**CalcPrivateCryptoSessionSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivatecryptosessionsize) function.

### `pfnCreateCryptoSession`

The entry point for the driver's [**CreateCryptoSession**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession) function.

### `pfnDestroyCryptoSession`

The entry point for the driver's [**DestroyCryptoSession**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroycryptosession) function.

### `pfnGetCertificateSize`

The entry point for the driver's [**GetCertificateSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificatesize) function.

### `pfnGetCertificate`

The entry point for the driver's [**GetCertificate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcertificate) function.

### `pfnNegotiateCryptoSessionKeyExchange`

The entry point for the driver's [**NegotiateCryptoSessionKeyExchange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiatecryptosessionkeyeschange) function.

### `pfnEncryptionBlt`

The entry point for the driver's [**EncryptionBlt(D3D11_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_encryptionblt) function.

### `pfnDecryptionBlt`

The entry point for the driver's [**DecryptionBlt(D3D11_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_decryptionblt) function.

### `pfnStartSessionKeyRefresh`

The entry point for the driver's [**StartSessionKeyRefresh**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_startsessionkeyrefresh) function.

### `pfnFinishSessionKeyRefresh`

The entry point for the driver's [**FinishSessionKeyRefresh**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_finishsessionkeyrefresh) function.

### `pfnGetEncryptionBltKey`

The entry point for the driver's [**GetEncryptionBltKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getencryptionbltkey) function.

### `pfnCalcPrivateAuthenticatedChannelSize`

The entry point for the driver's [**CalcPrivateAuthenticatedChannelSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivateauthenticatedchannelsize) function.

### `pfnCreateAuthenticatedChannel`

The entry point for the driver's [**CreateAuthenticatedChannel(D3D11_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel) function.

### `pfnDestroyAuthenticatedChannel`

The entry point for the driver's [**DestroyAuthenticatedChannel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_destroyauthenticatedchannel) function.

### `pfnNegotiateAuthenticatedChannelKeyExchange`

The entry point for the driver's [**NegotiateAuthenticatedChannelKeyExchange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiateauthenticatedchannelkeyexchange) function.

### `pfnQueryAuthenticatedChannel`

The entry point for the driver's [**QueryAuthenticatedChannel(D3D11_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel) function.

### `pfnConfigureAuthenticatedChannel`

The entry point for the driver's [**ConfigureAuthenticatedChannel(D3D11_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel) function.

### `pfnVideoDecoderGetHandle`

The entry point for the driver's [**VideoDecoderGetHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecodergethandle) function.

### `pfnCryptoSessionGetHandle`

The entry point for the driver's [**CryptoSessionGetHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_cryptosessiongethandle) function.

### `pfnVideoProcessorSetStreamRotation`

The entry point for the driver's [**VideoProcessorSetStreamRotation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamrotation) function.

### `pfnGetCaptureHandle`

The entry point for the driver's [**GetCaptureHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcapturehandle) function.

### `pfnGetDataForNewHardwareKey`

The entry point for the driver's [**GetDataForNewHardwareKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_getdatafornewhardwarekey) function.

### `pfnCheckCryptoSessionStatus`

The entry point for the driver's [**CheckCryptoSessionStatus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_checkcryptosessionstatus) function.

### `pfnVideoDecoderSubmitBuffers1`

The entry point for the driver's [**VideoDecoderSubmitBuffers1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videodecodersubmitbuffers1) function.

### `pfnQueryVideoCapabilities`

The entry point for the driver's [**QueryVideoCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities) function.

### `pfnCheckVideoProcessorFormatConversion`

The entry point for the driver's [**CheckVideoProcessorFormatConversion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_checkvideoprocessorformatconversion) function.

### `pfnVideoDecoderEnableDownsampling`

The entry point for the driver's [**VideoDecoderEnableDownsampling**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videodecoderenabledownsampling) function.

### `pfnVideoDecoderUpdateDownsampling`

The entry point for the driver's [**VideoDecoderUpdateDownsampling**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videodecoderupdatedownsampling) function.

### `pfnVideoProcessorSetStreamMirror`

The entry point for the driver's [**VideoProcessorSetStreamMirror**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videoprocessorsetstreammirror) function.

### `pfnVideoProcessorSetOutputColorSpace1`

The entry point for the driver's [**VideoProcessorSetOutputColorSpace1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videoprocessorsetoutputcolorspace1) function.

### `pfnVideoProcessorSetStreamColorSpace1`

The entry point for the driver's [**VideoProcessorSetStreamColorSpace1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videoprocessorsetstreamcolorspace1) function.

### `pfnVideoProcessorSetOutputShaderUsage`

The entry point for the driver's [**VideoProcessorSetOutputShaderUsage**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videoprocessorsetoutputshaderusage) function.

### `pfnVideoProcessorGetBehaviorHints`

The entry point for the driver's [**VideoProcessorGetBehaviorHints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videoprocessorgetbehaviorhints) function.

### `pfnGetCryptoSessionPrivateDataSize`

The entry point for the driver's [**GetCryptoSessionPrivateDataSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_getcryptosessionprivatedatasize) function.