//
// StatementCreator.h
//
// $Id: //poco/Main/Data/include/Poco/Data/StatementCreator.h#5 $
//
// Library: Data
// Package: DataCore
// Module:  StatementCreator
//
// Definition of the StatementCreator class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Data_StatementCreator_INCLUDED
#define Data_StatementCreator_INCLUDED


#include "Poco/Data/Data.h"
#include "Poco/Data/SessionImpl.h"
#include "Poco/Data/Statement.h"
#include "Poco/AutoPtr.h"


namespace Poco {
namespace Data {


class Data_API StatementCreator
	/// A StatementCreator creates Statements.
{
public:
	StatementCreator();
		/// Creates an unitialized StatementCreator.
		
	StatementCreator(Poco::AutoPtr<SessionImpl> ptrImpl);
		/// Creates a StatementCreator.

	StatementCreator(const StatementCreator& other);
		/// Creates a StatementCreator by copying another one.

	~StatementCreator();
		/// Destroys the StatementCreator.

	StatementCreator& operator = (const StatementCreator& other);
		/// Assignment operator.
		
	void swap(StatementCreator& other);
		/// Swaps the StatementCreator with another one.	
		
	template <typename T>
	Statement operator << (const T& t)
		/// Creates a Statement.
	{
		Statement stmt(_ptrImpl->createStatementImpl());
		stmt << t;
		return stmt;
	}

private:
	Poco::AutoPtr<SessionImpl> _ptrImpl;
};


} } // namespace Poco::Data


#endif // Data_StatementCreator_INCLUDED
