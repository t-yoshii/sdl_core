/**
 * @file CArraySchemaItem.hpp
 * @brief CArraySchemaItem header file.
 */
// Copyright (c) 2013, Ford Motor Company
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following
// disclaimer in the documentation and/or other materials provided with the
// distribution.
//
// Neither the name of the Ford Motor Company nor the names of its contributors
// may be used to endorse or promote products derived from this software
// without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 'A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef __SMARTOBJECT_CARRAYSCHEMAITEM_HPP__
#define __SMARTOBJECT_CARRAYSCHEMAITEM_HPP__

#include <stddef.h>

#include "utils/shared_ptr.h"
#include "ISchemaItem.hpp"
#include "CAlwaysTrueSchemaItem.hpp"
#include "TSchemaItemParameter.hpp"

namespace NsSmartDeviceLink
{
    namespace NsSmartObjects
    {
        /**
         * @brief Array schema item.
         **/
        class CArraySchemaItem: public ISchemaItem
        {
        public:
            /**
             * @brief Create a new schema item.
             *
             * @param ElementSchemaItem SchemaItem for array elements.
             * @param MinSize Minimum allowed size.
             * @param MaxSize Maximum allowed size.
             *
             * @return Shared pointer to a new schema item.
             **/
            static utils::SharedPtr<CArraySchemaItem> create(const utils::SharedPtr<ISchemaItem> & ElementSchemaItem = CAlwaysTrueSchemaItem::create(),
                                                       const TSchemaItemParameter<size_t> & MinSize = TSchemaItemParameter<size_t>(),
                                                       const TSchemaItemParameter<size_t> & MaxSize = TSchemaItemParameter<size_t>());

            /**
             * @brief Validate smart object.
             *
             * @param Object Object to validate.
             *
             * @return NsSmartObjects::Errors::eType
             **/
            virtual Errors::eType validate(const NsSmartDeviceLink::NsSmartObjects::CSmartObject & Object);

            /**
             * @brief Apply schema.
             *
             * @param Object Object to apply schema.
             **/
            virtual void applySchema(NsSmartDeviceLink::NsSmartObjects::CSmartObject & Object);

            /**
             * @brief Unapply schema.
             *
             * @param Object Object to unapply schema.
             **/
            virtual void unapplySchema(NsSmartDeviceLink::NsSmartObjects::CSmartObject & Object);

            /**
             * @brief Build smart object by smart schema
             *
             * Fill smart object with default values
             *
             * @param object Object to build
             **/
            virtual void BuildObjectBySchema(NsSmartDeviceLink::NsSmartObjects::CSmartObject& object);

        private:
            /**
             * @brief Constructor.
             *
             * @param ElementSchemaItem SchemaItem for array elements.
             * @param MinSize Minimum allowed size.
             * @param MaxSize Maximum allowed size.
             **/
            CArraySchemaItem(const utils::SharedPtr<ISchemaItem> & ElementSchemaItem,
                             const TSchemaItemParameter<size_t> & MinSize,
                             const TSchemaItemParameter<size_t> & MaxSize);

            /**
             * @brief Copy constructor.
             *
             * Not implemented to prevent misuse.
             *
             * @param Other Other schema item.
             **/
            CArraySchemaItem(const CArraySchemaItem & Other);

            /**
             * @brief Assignment operator.
             *
             * Not implemented to prevent misuse.
             *
             * @param Other Other schema item.
             *
             * @return Not implemented.
             **/
            CArraySchemaItem & operator =(const CArraySchemaItem & Other);

            /**
             * @brief SchemaItem for array elements.
             **/
            const utils::SharedPtr<ISchemaItem> mElementSchemaItem;

            /**
             * @brief Minimum allowed size.
             **/
            const TSchemaItemParameter<size_t> mMinSize;

            /**
             * @brief Maximum allowed size.
             **/
            const TSchemaItemParameter<size_t> mMaxSize;
        };
    }
}

#endif
