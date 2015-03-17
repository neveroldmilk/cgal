namespace CGAL {

/*!
\ingroup PkgRidges_3Enums
The enum `Umbilic_type` describes the types for the class `Umbilic`.
\sa `Umbilic`
*/
enum Umbilic_type { NON_GENERIC_UMBILIC, ELLIPTIC_UMBILIC, HYPERBOLIC_UMBILIC };


/*!
\ingroup PkgRidges_3

The function `compute_umbilics()` is a shortcut to the 
method `Umbilic_approximation::compute()`.  See `Umbilic_approximation::Umbilic_approximation()` for an explanation of the parameters.


*/
template < class TriangleMesh, 
class VertexFTMap,
class VertexVectorMap,
class OutputIterator>
OutputIterator compute_umbilics(const TriangleMesh &tm,
                                VertexFTMap vertex_k1_pm, 
                                VertexFTMap vertex_k2_pm,
                                VertexVectorMap vertex_d1_pm, 
                                VertexVectorMap vertex_d2_pm,
                                OutputIterator it, 
double size);

} /* namespace CGAL */


namespace CGAL {

/*!
\ingroup PkgRidges_3

The class `Umbilic_approximation` computes the approximation of 
umbilics on a triangular polyhedral surface. 

\tparam TriangleMesh is the surface type. 
\tparam VertexFTMap
bUm\tparam VertexVectorMap provide 
the differential properties of the surface associated to its vertices. 

Requirements (checked at compile time) : 
- the types `TriangleMesh::Traits::FT` and 
  `boost::property_traits<VertexFTMap>::%value_type` must coincide;
- the types `TriangleMesh::Traits::Vector_3` and 
  `boost::property_traits<VertexVectorMap::%value_type` must coincide; 
- the types `boost::graph_traits<TriangleMesh>::%vertex_descriptor`, 
  `boost::property_traits<VertexFTMap>::%key_type` and 
  `boost::property_traits<VertexVectorMap>::%key_type` must coincide; 

\sa `Umbilic` 
\sa `TriangleMesh` 
\sa `VertexFTMap` 
\sa `VertexVectorMap` 

*/
template< typename TriangleMesh, typename VertexFTMap, typename VertexVectorMap >
class Umbilic_approximation {
public:

/// \name Types 
/// @{

/*!

*/ 
typedef typename TriangleMesh::Traits::FT FT; 

/// @} 

/// \name Creation 
/// @{

/*!
Constructor. 

\param tm the triangle mesh
\param vertex_k1_pm maximal principal curvatures
\param vertex_k2_pm minimal principal curvatures
\param vertex_d1_pm maximal principal directions of curvature
\param vertex_d2_pm minimal principal directions of curvature
*/ 
Umbilic_approximation(const TriangleMesh& tm, 
                      VertexFTMap vertex_k1_pm, 
                      VertexFTMap vertex_k2_pm, 
                      VertexVectorMap vertex_d1_pm, 
                      VertexVectorMap vertex_d2_pm); 
  
/// @} 

/// \name Operations 
/// @{

/*!
Performs the approximation, `size` determines the size of the 
patches around vertices, taken as `size` times the size of the 
1-ring. Umbilics are inserted into `it`.

\tparam OutputIterator an output iterator with value type `Umbilic*`. 
*/ 
template <class OutputIterator> OutputIterator compute(OutputIterator it, FT size); 

/// @}

}; /* end Umbilic_approximation */
} /* end namespace CGAL */

namespace CGAL {

/*!
\ingroup PkgRidges_3

The class `Umbilic` stores the description of an umbilic. 

\sa `Umbilic_approximation` 

*/
template< typename TriangleMesh >
class Umbilic {
public:

/// \name Types 
/// @{

/*!

*/ 
  typedef typename boost::graph_traits<TriangleMesh>::vertex_descriptor vertex_descriptor; 

/*!

*/ 
typedef typename TriangleMesh::halfedge_descriptor halfedge_descriptor; 

/// @} 

/// \name Access Functions 
/// @{

/*!

*/ 
vertex_descriptor vertex() const; 

/*!

*/ 
Umbilic_type umbilic_type() const; 

/*!

*/ 
const std::list<halfedge_descriptor>& contour_list()const; 

/// @}

}; /* end Umbilic */

/*!
\relates Umbilic

Writes the location and the umbilic type to `os`.
*/
template< typename TriangleMesh >
std::ostream& operator<<(std::ostream& os, const Umbilic<TriangleMesh>& u);

} /* end namespace CGAL */
