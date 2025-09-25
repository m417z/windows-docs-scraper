MFCreateVideoMixerAndPresenter Mfcreatevideomixerandpresenter;

EVRPUBLIC Mfcreatevideomixerandpresenter(
  [in]  IUnknown *pMixerOwner,
  [in]  IUnknown *pPresenterOwner,
  [in]  REFIID riidMixer,
  [out] void **ppvVideoMixer,
  [in]  REFIID riidPresenter,
  [out] void **ppvVideoPresenter
)
{...}