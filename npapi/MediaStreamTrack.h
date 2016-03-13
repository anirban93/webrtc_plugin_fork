/* Copyright(C) 2014-2016 Doubango Telecom <https://github.com/sarandogou/webrtc-everywhere> */
#ifndef _WEBRTC_EVERYWHERE_NPAPI_MEDIASTREAMTRACK_H_
#define _WEBRTC_EVERYWHERE_NPAPI_MEDIASTREAMTRACK_H_

#include "../common/_Config.h"
#include "../common/_Common.h"
#include "../common/_MediaStreamTrack.h"
#include "../common/_AsyncEvent.h"

#include "npapi-includes.h"

class MediaStreamTrack
	: public NPObject
	, public _AsyncEventRaiser
	, public _UniqueObject
{
public:
	MediaStreamTrack(NPP instance);
	virtual ~MediaStreamTrack();

public:
	static NPObject* Allocate(NPP instance, NPClass* npclass);
	static void Deallocate(NPObject* obj);
	static bool HasMethod(NPObject* obj, NPIdentifier methodName);
	static bool InvokeDefault(NPObject* obj, const NPVariant* args,
		uint32_t argCount, NPVariant* result);
	static bool Invoke(NPObject* obj, NPIdentifier methodName,
		const NPVariant* args, uint32_t argCount,
		NPVariant* result);
	static bool HasProperty(NPObject* obj, NPIdentifier propertyName);
	static bool GetProperty(NPObject* obj, NPIdentifier propertyName,
		NPVariant* result);
	static bool SetProperty(NPObject *npobj, NPIdentifier name, const NPVariant *value);
	static bool RemoveProperty(NPObject *npobj, NPIdentifier name);
	static bool NPEnumeration(NPObject *npobj, NPIdentifier **value,
		uint32_t *count);
	static void Invalidate(NPObject *npobj);
	static bool Construct(NPObject *npobj, const NPVariant *args, uint32_t argCount, NPVariant *result);

	NPObjectImpl_CreateInstanceWithRef(MediaStreamTrack);
	NPObjectImpl_NPObjectRelease(MediaStreamTrack);
	NPObjectImpl_IsInstanceOf(MediaStreamTrack);

	void SetTrack(cpp11::shared_ptr<_MediaStreamTrack> & track);
	cpp11::shared_ptr<_MediaStreamTrack> GetTrack();

	// not part of the standard but used by Chrome
	static NPError getSources(NPP npp, _AsyncEventDispatcher* dispatcher, NPObject** Infos);

private:

	void onmute();
	void onunmute();
	void onstarted();
	void onended();
	void onoverconstrained();

private:
	NPP m_npp;
	cpp11::shared_ptr<_MediaStreamTrack> m_Track;
	NPObject* m_callback_onmute;
	NPObject* m_callback_onunmute;
	NPObject* m_callback_onstarted;
	NPObject* m_callback_onended;
	NPObject* m_callback_onoverconstrained;
};

#endif /* _WEBRTC_EVERYWHERE_NPAPI_MEDIASTREAMTRACK_H_ */
