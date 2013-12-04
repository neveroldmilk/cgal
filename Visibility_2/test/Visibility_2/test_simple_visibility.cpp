// Copyright (c) 2013 Technical University Braunschweig (Germany).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
// You can redistribute it and/or modify it under the terms of the GNU
// General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
//
// Author(s):  Francisc Bungiu <fbungiu@gmail.com>
//             Michael Hemmer <michael.hemmer@cgal.org>

#include <CGAL/basic.h>
#include <CGAL/Cartesian.h>
#include <CGAL/Gmpq.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Arr_segment_traits_2.h>
#include <CGAL/Arrangement_2.h>
#include <CGAL/test_model_methods.h>
#include <CGAL/test_utils.h>
#include <CGAL/Simple_polygon_visibility_2.h>
#include <CGAL/Arr_extended_dcel.h>


#include <iostream>
#include <fstream>

int main() {
{
  typedef CGAL::Gmpq                                        Number_type;
  typedef CGAL::Cartesian<Number_type> 							        Kernel;
  typedef CGAL::Arr_segment_traits_2<Kernel> 						    Traits_2;
  typedef Traits_2::Point_2										              Point_2;
  typedef Traits_2::X_monotone_curve_2							        Segment_2;
  typedef CGAL::Arrangement_2<Traits_2>							        Arrangement_2;
  typedef CGAL::Simple_polygon_visibility_2<Arrangement_2, Arrangement_2, CGAL::Tag_false>
                                                    Simple_polygon_visibility_2;
  std::cout << "Running model tests - ";
  CGAL::test_model_methods<Simple_polygon_visibility_2>();
  std::cout << GREEN << "Done!" << RESET << std::endl;
  std::cout << "Running test suite with " << GREEN 
            << "Cartesian" << RESET << " Kernel..." << std::endl;
  CGAL::run_tests<Simple_polygon_visibility_2>(17, 0);
}
{
  typedef CGAL::Exact_predicates_exact_constructions_kernel  Kernel;
  typedef CGAL::Arr_segment_traits_2<Kernel>                 Traits_2;
  typedef Traits_2::Point_2                                  Point_2;
  typedef Traits_2::X_monotone_curve_2                       Segment_2;
  typedef CGAL::Arrangement_2<Traits_2>                      Arrangement_2;
  typedef CGAL::Simple_polygon_visibility_2<Arrangement_2, Arrangement_2, CGAL::Tag_false>
                                                    Simple_polygon_visibility_2;
  std::cout << "Running model tests - ";
  CGAL::test_model_methods<Simple_polygon_visibility_2>();
  std::cout << GREEN << "Done!" << RESET << std::endl;
  std::cout << "Running test suite with " << GREEN 
            << "EPECK" << RESET << " Kernel..." << std::endl;
  CGAL::run_tests<Simple_polygon_visibility_2>(17, 0);
}
{
  // test Visibility_arrangement_type with extended DCEL     
  typedef CGAL::Exact_predicates_exact_constructions_kernel       Kernel;
  typedef CGAL::Arr_segment_traits_2<Kernel>                      Traits_2;
  typedef CGAL::Arrangement_2<Traits_2> ARR; 
  typedef CGAL::Arr_extended_dcel<Traits_2, bool, bool, bool> EDCEL; 
  typedef CGAL::Arrangement_2<Traits_2, EDCEL> EARR;   
  {
    typedef CGAL::Simple_polygon_visibility_2<ARR,EARR,CGAL::Tag_true> Visibility_2;
    CGAL::test_model_methods<Visibility_2>();
    CGAL::run_tests<Visibility_2>(17, 2);
  }{
    typedef CGAL::Simple_polygon_visibility_2<ARR,EARR,CGAL::Tag_false> Visibility_2;
    CGAL::test_model_methods<Visibility_2>();
    CGAL::run_tests<Visibility_2>(17, 2);
  }
}

  return 0;
}
