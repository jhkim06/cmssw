#ifndef Fireworks_Core_FWGeometryTableView_h
#define Fireworks_Core_FWGeometryTableView_h
// -*- C++ -*-
//
// Package:     Core
// Class  :     FWGeometryTableView
// 
/**\class FWGeometryTableView FWGeometryTableView.h Fireworks/Core/interface/FWGeometryTableView.h

 Description: [one line class summary]

 Usage:
    <usage>

*/
//
// Original Author:  
//         Created:  Wed Jan  4 00:05:38 CET 2012
// $Id: FWGeometryTableView.h,v 1.8 2012/05/02 04:44:36 amraktad Exp $
//

#include "Fireworks/Core/interface/FWGeometryTableViewBase.h"
class FWGeometryTableManagerBase;
class FWGeometryTableManager;
class FWGUIValidatingTextEntry;
class FWGeoMaterialValidator;
class FWEveDetectorGeo;

class FWGeometryTableView : public FWGeometryTableViewBase
{
public:
   enum EMode          { kNode, kVolume };
   enum EProximityAlgo { kBBoxCenter, kBBoxSurface };

public:
   FWGeometryTableView(TEveWindowSlot* iParent, FWColorManager* colMng);
   virtual ~FWGeometryTableView();
   virtual void populateController(ViewerParameterGUI&) const;
   virtual  FWGeometryTableManagerBase*  getTableManager();

   void filterListCallback();
   void filterTextEntryCallback();
   void updateFilter(std::string&);

   bool getVolumeMode()      const { return m_mode.value() == kVolume; }
   std::string getFilter()   const { return m_filter.value(); }
   int  getAutoExpand()      const { return m_autoExpand.value(); }
   int  getVisLevel()        const { return m_visLevel.value(); }
   bool getIgnoreVisLevelWhenFilter() const { return m_visLevelFilter.value(); }

   bool getFilterByName() const { return m_filterByName.value(); }

   bool drawTopNode() const { return ! m_disableTopNode.value(); }
   void autoExpandCallback();
   virtual void setPath(int, std::string&);   
   virtual void setFrom(const FWConfiguration&);

  // void chosenItem(int);
   void updateVisibilityTopNode();
   
   void checkRegionOfInterest();
   bool isSelectedByRegion() const { return m_selectRegion.value(); } 
   
protected:
   // virtual void initGeometry(TGeoNode* iGeoTopNode, TObjArray* iVolumes);

private:
   FWGeometryTableView(const FWGeometryTableView&); // stop default
   const FWGeometryTableView& operator=(const FWGeometryTableView&); // stop default

   // ---------- member data --------------------------------
   FWGeometryTableManager   *m_tableManager;

   FWGUIValidatingTextEntry *m_filterEntry;
   FWGeoMaterialValidator   *m_filterValidator;

#ifndef __CINT__ 
   FWEnumParameter         m_mode;
   FWBoolParameter         m_disableTopNode;
   FWLongParameter         m_visLevel;

   FWStringParameter       m_filter; 
   FWBoolParameter         m_filterByName;
   FWBoolParameter         m_visLevelFilter; 
   
   FWBoolParameter         m_selectRegion;
   FWDoubleParameter       m_regionRadius;
   FWEnumParameter         m_proximityAlgo;
   
   

#endif  

   ClassDef(FWGeometryTableView, 0);
};

#endif
